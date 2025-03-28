import unittest
import subprocess as sp
import os
import sys

amacc='./amacc'
gcc= os.getenv("CROSS_COMPILE","arm-none-linux-gnueabinf-")+"gcc"
amaccdir='elf'
gccdir='out-gcc'

class TestCC_UC(unittest.TestCase):
    """ Test cases without -fsigned-char (default) """
    pass


def mkdir_p(path):
    try:
        os.makedirs(path)
    except OSError as exc:
        if  os.path.isdir(path):
            print("directory exist")
            pass
        else:
            raise


def generate_test(test_name,test_file,extra_cflags):
    def test(self):
        args=['3']
        
        test_file_name=os.path.splitext(os.path.basename(test_file))[0]
        
        prog_exe=os.path.join(gccdir,test_file_name)
        
        gcc_params=[gcc,'-w','-o',prog_exe,test_file]+extra_cflags
        sp.run(gcc_params)

        proc=sp.run(qemuCmd+[prog_exe]+args,timeout=10,stdout=sp.PIPE)
        gcc_out,gcc_err,gcc_retcode=proc.stdout,proc.stderr,proc.returncode

        amacc_params=[amacc]+extra_cflags+[test_file]+args
        proc=sp.run(qemuCmd+amacc_params,proc.stdout,proc.stderr,proc.returncode)
        amacc_out, amacc_err, amacc_retcode = proc.stdout, proc.stderr, proc.returncode
        self.assertEqual(amacc_out.decode('utf-8'), gcc_out.decode('utf-8'))
        self.assertEqual(amacc_retcode, gcc_retcode)

        prog_exe = os.path.join(amaccdir, test_file_name)
        amacc_params = [amacc] + extra_cflags + ['-o', prog_exe, test_file]
        sp.run(qemuCmd + amacc_params)

        proc = sp.run(qemuCmd + [prog_exe] + args, timeout=10, stdout=sp.PIPE)
        amacc_out, amacc_err, amacc_retcode = proc.stdout, proc.stderr, proc.returncode
        self.assertEqual(amacc_out.decode('utf-8'), gcc_out.decode('utf-8'))
        self.assertEqual(amacc_retcode, gcc_retcode)

        

    return test

        

        

def define_tests():
    if not os.access(amaccdir,os.F_OK):
        mkdir_p(amaccdir)
    if not os.access(gccdir,os.F_OK):
        mkdir_p(gccdir)
    
    for dirpath, _ ,filenames in os.walk('test'):
        for f in filenames:
            if f.endswith('.c'):
        
                test_file = os.path.abspath(os.path.join(dirpath,f))
                test_name='test_%s' % (os.path.splitext(f)[0])

                # print("test_file:",test_file)
                # print("test_name:",test_name)

                test_func=generate_test(test_name,test_file,[])
                setattr(TestCC_UC,test_name,test_func)
                
                

    
define_tests()

if __name__ == '__main__':
    try:
        qemuCmd = os.getenv('ARM_EXEC').split()

    except AttributeError:
        qemuCmd = 'qemu-arm -L /usr/arm-linux-gnueabihf'.split()
    unittest.main()