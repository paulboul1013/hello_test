class car():

    def __init__(self,make,model,year):
        self.make=make
        self.model=model
        self.year=year
        self.odometer_read=0

    def get_desciptive(self)->str:

        long_name=str(self.make)+' '+str(self.model)+" "+str(self.year)

        return long_name.title()
    
    def read_odometer(self):
        print("This car has "+str(self.odometer_read)+" miles on")

        

    def update_odometer(self,mileage):
        if mileage >=self.odometer_read:
            self.odometer_read=mileage
        else:
            print("you can't roll back an odometer!")

    def increment_odometer(self,miles):
        self.odometer_read+=miles


class Battery():

    def __init__(self,battery_size=70):
        self.battery_size=battery_size

    def describe_battery(self):
        print("This car has a "+str(self.battery_size)+" -KWh battery")

    def get_range(self):

        if self.battery_size==70:
            range=240

        elif self.battery_size==85:
            range=270

        message="This car can go approximately "+str(range)
        message+=" miles on a full charge"

        print(message)

    def update_battery(self):
        if self.battery_size!=85:
            self.battery_size=85

        
class electric_car(car):
    
    def __init__(self,make,model,year):
        super().__init__(make,model,year)
        self.battery=Battery()

    # def descirble_battery(self):
    #     print("This car has a "+str(self.battery_size)+" -KWh battery")

    def fill_gas_tank():
        print("This car doesn't need a gas tank!!")