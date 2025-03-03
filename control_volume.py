import time
import threading
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
from comtypes import CLSCTX_ALL
import sys

class EnhancedVolumeController:
    def __init__(self):
        self.volume_interface = self._get_volume_interface()
    
    def _get_volume_interface(self):
        """獲取音頻接口"""
        devices = AudioUtilities.GetSpeakers()
        interface = devices.Activate(
            IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
        return interface.QueryInterface(IAudioEndpointVolume)
    
    def get_volume(self):
        """獲取當前音量 (0-100 百分比)"""
        return round(self.volume_interface.GetMasterVolumeLevelScalar() * 100)
    
    def set_volume(self, level):
        """設置音量 (0-100)"""
        if not 0 <= level <= 100:
            raise ValueError("音量範圍必須在 0-100 之間")
        self.volume_interface.SetMasterVolumeLevelScalar(level/100, None)
    
    def get_mute_status(self):
        """獲取當前靜音狀態"""
        return self.volume_interface.GetMute()
    
    def toggle_mute(self):
        """切換靜音狀態"""
        current_status = self.get_mute_status()
        self.volume_interface.SetMute(not current_status, None)
    
    def unmute(self):
        """強制解除靜音"""
        self.volume_interface.SetMute(0, None)
    
    def volume_up(self, step=5):
        """增大音量"""
        current = self.get_volume()
        self.set_volume(min(100, current + step))
    
    def volume_down(self, step=5):
        """降低音量"""
        current = self.get_volume()
        self.set_volume(max(0, current - step))


def main():
    try:
        vc = EnhancedVolumeController()
        


        while True:
            print("\n選單:")
            print("1. 設定絕對音量")
            print("2. 增加音量 (+5%)")
            print("3. 降低音量 (-5%)")
            print("4. 切換靜音狀態")
            print("5. 強制解除靜音")
            print("6. 退出")
            
            choice = input("請選擇操作 (1-6): ").strip()
            
            if choice == '1':
                try:
                    level = int(input("輸入音量 (0-100): "))
                    vc.set_volume(level)
                    vc.unmute()  # 設置音量時自動解除靜音
                except ValueError:
                    print("無效輸入！")
            elif choice == '2':
                vc.volume_up()
                vc.unmute()  # 調整音量時自動解除靜音
            elif choice == '3':
                vc.volume_down()
                vc.unmute()  # 調整音量時自動解除靜音
            elif choice == '4':
                vc.toggle_mute()
            elif choice == '5':
                vc.unmute()
                print("已強制解除靜音")
            elif choice == '6':
                print("程式結束")
                sys.exit()
            else:
                print("無效選擇！")
                
    except Exception as e:
        print(f"發生錯誤: {str(e)}")
        sys.exit(1)

if __name__ == "__main__":
    main()