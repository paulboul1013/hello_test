from collections import OrderedDict
from random import randint
# name="ada lovelac" #字首轉大寫
# print(name.title())


# print(name.upper())
# print(name.lower())

# first_name="ada"
# last_name="lovelace"
# full_name=first_name+" "+last_name
# print(full_name)

# print("hello, "+full_name.title()+"!")


# message="hello, "+full_name.title()+"!"
# print(message)

# print("Python")
# print("\tPython")
# print("Langguages:\nPython\nC\nJavaScript")
# print("Langguages:\n\tPython\n\tC\n\tJavaScript")


# fav_lang='python '
# print(fav_lang.rstrip())  #削掉尾部空白

# fav_lang=fav_lang.rstrip()
# print(fav_lang)

# fav_lang=' python' 
# print(fav_lang.lstrip()) #削掉頭部空白

# fav_lang=' python '
# print(fav_lang.strip()) #削掉頭尾部空白


# user_name=" Eric "
# print("Hello "+user_name+ ", would you like to learn some Python today?")

# print(user_name.upper())
# print(user_name.lower())
# print(user_name.title())

# famous_person=user_name+" is a youtuber"
# print(famous_person)

# print("\t"+user_name+"\n"+famous_person)

# print(user_name.lstrip())
# print(user_name.rsplit())
# print(user_name.strip())


# age=23
# message="Happy "+str(age)+" rd Birthday"
# print(message) 


# print(3/2) # 1.5
# print(3%2) # 1
# print(3.0/2)
# print(3.0/2.0)

# print(2+6)
# print(2*4)
# print(10-2) #8.0
# print(16/2)


# bicyles=['trek','cannodale','redline','specialezed']
# print(bicyles)
# print(bicyles[0])
# print(bicyles[0].title())
# print(bicyles[1])
# print(bicyles[3])
# print(bicyles[-1])

# message="My First bicycle as a "+bicyles[0].title()+"."
# print(message)

# names=["paul","kk","felian","parot"]
# print(names)


# name_1:str=names[0]
# print(name_1+" welcome ")


# moto=['honda','yamaha','suzuki']

# print(moto)
# moto[0]='ducati'
# print(moto)

# moto.append('apple')
# print(moto)

# moto=[]
# print(moto)

# moto.append('honda')
# moto.append('yamaha')
# moto.append('suzuki')
# print(moto)

# moto.insert(0,'ducati')
# print(moto)


# del moto[0]
# print(moto)

# del moto[1]
# print(moto)

# moto=['honda','yamaha','suzuki']


# poped=moto.pop()
# print(moto)
# print(poped)

# last_owned=moto.pop()
# print("The last motorcycle I owned was a "+last_owned.title()+".")

# first_owned=moto.pop(0)
# print(first_owned)

# moto=['honda','yamaha','suzuki']

# too_expensive='suzuki'
# moto.remove(too_expensive)
# print(moto)

# invite=["paul","dona","東和"]
# remove_person=invite.pop(0)
# invite[0]="big boss"
# print(remove_person)
# print(invite)
# invite.append("filain")
# print(invite)
# invite.insert(0,"99")
# print(invite)
# invite.insert(int(len(invite)/2),"lady gaga")
# print(invite)
# invite.insert(len(invite),"nemomo")
# print(invite)

# for i  in range(len(invite)):
#     if (len(invite)==2):
#         print(invite[0]+" still in the invite list")
#         print(invite[1]+" still in the invite list")
#         break

#     del_person=invite.pop()
#     print("sorry to cancel deer "+del_person)
#     i=i+1

# del invite
# invite=[]
# print(invite)

# cars=['bmw','audi','toyota','subaru']
# cars.sort()
# print(cars)

# cars.sort(reverse=True)
# print(cars)

# print(sorted(cars))#臨時排序

# cars.reverse()
# print(cars)

# print(len(cars))

# print(cars[-1])


# magicians=["alice","david","carolina"]
# for m in magicians:
#     print(m.title()+", that was a great trick!")
#     print("I can't wait to see your next trick, "+m.title()+'\n')




# pizza=["kk","東河","田野優"]

# for p in pizza:
#     print("i like "+p.title()+'\n')

# print("i love pizza")


# for value in range(1,5):
#     print(value)

# for value in range(1,6):
#     print(value)


# numbers=list(range(1,6))
# print(numbers)


# even_numbers=list(range(2,11,2))
# print(even_numbers)

# squares=[]
# for value in range(1,11):
#     squares.append(value**2)

#     print(squares)


# digits=list(range(1,1000))
# print(min(digits))
# print(max(digits))
# print(sum(digits))


# squares=[value**2 for value in range(1,20)]
# print(squares)


# for i in range(1,21):
#     print(i)

# one=list(range(1,1000000))
# for i in one:
#     print(i)

# print(sum(one))
# print(max(one))
# print(min(one))

# one=[value*2+1 for value in range(3,11)]
# for  i in one:
#     print(i)


# one=[value for value in range(1,31)]
# for i in one:
#     if i%3==0:
#         print(i)

# one=[value**3 for value in range(1,10)]
# for i in one:
#     print(i)

# one=[value**2 for value in range(1,10)]

# players=['charles','martina','michael','florence','ela']
# print(players[0:3])
# print(players[1:4])
# print(players[:4])
# print(players[2:])
# print(players[-3:])

# for player in players[:3]:
#     print(player)


# my_foods=['pizza','falafel','carrot cake']
# friend_foods=my_foods[:] #copy all list

# print(my_foods)
# print(friend_foods)

# friend_foods=my_foods[:] #copy all list


# my_foods.append("cannoli")
# friend_foods.append("ice cream")



# print(my_foods)
# print(friend_foods)

# str="The first from the middle of the list are:"
# print(str[:15])
# print(str[10:26])
# print(str[-13:])

# pizza_1=["apple","pineapple","chieese"]
# f_pizza=pizza_1[:]

# for i in pizza_1:
#     print(i)

# for i in f_pizza:
#     print(i)


# dimension=(200,50)
# # print(dimension[0])
# # print(dimension[1])


# for d in dimension:
#     print(d)


# dimension=(300,22)
# for d in dimension:
#     print(d)


# dinner=('apple','meet','goat','chicken','egg')
# for d in dinner:
#     print(d)

# # dinner[3]='d'

# dinner=('apple','bee','tea','chicken','egg')
# for d in dinner:
#     print(d)


# cars=['audi','bmw','subaru','toyota']

# for car in cars:
#     if car=='bmw':
#         print(car.upper())
#     else:
#         print(car.title())

# car='Audi'
# print(car.lower()=='audi')

# topping="mushroom"

# if topping!='anchovies':
#     print("hold the anchovies!")


# age0=21
# age1=18

# print(age0>=21 and age1>=21)

# age1=22
# print(age0>=21 and age1>=21)


# print("audi" in cars)

# banned_users=['andrew','carolina','david']
# user='mrie'

# if user not in banned_users:
#     print(user.title()+", you can post a response if you wish")

# game_active=True
# can_edit=False

# car='sub'
# print(car=='sub')
# print(car=='audi')

# print(len(car)==len('audi'))
# print('audi ' in car)
# print('audi ' not in car)

# age=12
# price=0

# if age<4:
#     price=0
# elif age<18:
#     price=5
# elif age<65:
#     price=10
# else:
#     price=5

# print("you admission cost is $"+str(price)+".")

# requesetd_toppings=['mushroom','extra cheese']

# if 'mushroom' in requesetd_toppings:
#     print("adding mushroom")

# if 'pepperoni' in requesetd_toppings:
#     print("adding pepperoni.")

# if 'extra cheese' in requesetd_toppings:
#     print('adding extra cheese')


# alien_color=['green','yellow','red']
# point=0
# alien='red'
# if alien == 'green':
#     point+=5
# elif alien=='yellow':
#     point+=10
# else:
#     point+=15

# print(point)


# age=1
# if age<2:
#     print("babby")
# elif age>=2 and age<4:
#     print('walking babby')
# elif age>=4 and age<13:
#     print("child")
# elif age>=13 and age<20:
#     print("teenager")
# elif age>=20 and age<65:
#     print("adult")
# else:
#     print("old man")

# fav_fruits=["apple","kiwi","banana"]

# for i in fav_fruits:
#     if "apple" in i:
#         print(i)
#     elif "kiwi" in i:
#         print(i)
#     else:
#         print(i)


# requested_toppings=[]

# if requested_toppings:
#     for topping in requested_toppings:
#         print("adding "+topping)
#     print("finished")

# else:
#     print("are you sure you want a plain pizza?")


# ava_toppings=['mushroom','olives','extra cheese']
# requested=['mushroom','pipeapple','extra cheese']

# for request_top in requested:
#     if request_top in ava_toppings:
#         print("adding "+request_top)
#     else:
#         print("sorry we don't have "+request_top+'.')


# user_list=['admin','kk','paul','shyla','bee']

# if user_list:
#     for u in user_list:
        
#         if u=='admin':
#             print("hello admin,would you like to see a status report?")
        
#         else:
#             print("Hello "+u+" thank you for logging in agian")

# else:
#     print("we need to find some users")
    

# del user_list
# user_list=[]
# print(user_list)

# current_user_list=['admin','kk','paul','shyla','bee','John']
# new_current_list=current_user_list[:2]
# print(new_current_list)

# for user in current_user_list:
#     if 'John' in user:
#         print("refuse this person")
#     if user in new_current_list:
#         print(user)
#     else:
#         print("need input other name")

# number=[value for value in range(1,10)]
# print(number)

# for value in number:
#     if value<=3:
#         print(str(value)+"st")
#     else:
#         print(str(value)+"th")


# alien_o={'color':'green','points':5}
# print(alien_o['color'])
# print(alien_o['points'])

# new_points=alien_o['points']+3
# print("you just earned "+str(new_points)+" points")

# alien_o['x_pos']=0
# alien_o['y_pos']=25
# print(alien_o)

# alien_o={}
# alien_o['color']='green'
# alien_o['points']=32
# print(alien_o)

# alien_o['color']='yellow'
# print(alien_o)

# alien_o={'x_pos':0,'y_pos':25,'speed':'fast'}
# print("original x-pos "+str(alien_o['x_pos']))

# if alien_o['speed']=='slow':
#     x_increment=1
# elif alien_o['speed']=='medium':
#     x_increment=2
# else:
#     x_increment=3

# alien_o['x_pos']=alien_o['x_pos']+x_increment
# print("new x-pos "+str(alien_o['x_pos']))

# del alien_o['speed']
# print(alien_o)


# fav_lang={
#     'jen':'python',
#     'sarah':'c',
#     'edward':'ruby',
#     'phil':'python'
# }


# print("sarah's favorite language is "+
#       fav_lang['sarah'].title()+
#       ".")



# d={"cache":"快速保存資料","memory":"用binary方式保存data和instruction"}

# print(d['cache']+'\n')
# print(d['memory']+'\n')


# user_0={
#     'username':'efermi',
#     'first':'enrico',
#     'last':'fermi'
# }

# for key,value in user_0.items():
#     print("\nKey:"+key)
#     print("Value:"+value)

# for name,lag in fav_lang.items():
#     print(name.title()+" s favorite language is "+lag.title()+".")

# for name in fav_lang.keys():
#     print(name.title())

# friends=['phil','paul']
# for name in fav_lang.keys():
#     print(name.title())
    

#     if name in friends:
#         print(" hi "+ name.title()+", I see your favorite language is "+fav_lang[name].title()+"!")
        

# if 'erin' not in fav_lang.keys():
#     print("erin,pleast take our poll")


# for name in sorted(fav_lang.keys()):
#     print(name.title()+" thank you for taking the poll.")

# for lang in fav_lang.values():
#     print(lang.title())


# for lang in set(fav_lang.values()):
#     print(lang.title())


# alien_0={'color':'green','point':5}
# alien_1={'color':'yellow','point':555}
# alien_2={'color':'red','point':35}


# alien=[alien_0,alien_1,alien_2]

# for a in alien:
#     print(a)


# aliens=[]

# for alien_number in range(30):
#     new_alien={'color':'green','point':5,'speed':'slow'}
#     aliens.append(new_alien)


# for alien in aliens[:5]:
#     print(alien)

# print(str(len(aliens)))


# for alien in aliens[0:3]:
#     if alien['color']=='green':
#         alien['color']='yellow'
#         alien['speed']='medium'
#         alien['point']=100


# for alien in aliens[0:3]:
#     print(alien)


# pizza ={
#     'crust':'thick',
#     'toppings':['mushroom','extra cheese'],
# }

# print("you ordered a ",pizza['crust']+"-crust pizza"+"with the following toppings")

# for topping in pizza['toppings']:
#     print('\t'+topping)


# fav_lang={
#     'jen':['python','ruby'],
#     'sarah':['c'],
#     'edward':['ruby','go'],
#     'phil':['python','haskell']
# }

# for name ,lang in fav_lang.items():
#     print("\n"+name.title()+" 's favorite languages are:")
#     for lag in lang:
#         print("\t"+lag.title())


# users={
#     'aeinstein':{
#         'first':'albert',
#         'last':'einstein',
#         'location':'princeton',
#     },

#     'mcurie':{
#         'first':'marie',
#         'last':'curie',
#         'location':'paris',
#     }
# }

# for username,user_info in users.items():
#     print("\nUsername: "+username)
#     full_name=user_info['first']+" "+user_info['last']
#     location=user_info['location']

#     print("\tFull name: "+full_name.title())
#     print("\tLocation: "+location.title())
    

# person1={"name":"paul","age":32}
# person2={"name":"dog","age":33}

# peoeple=[person1,person2]

# for i in peoeple:
#     print(i['name'])
#     print(i['age'])



# crzay={"type":"dog","master":"paul"}
# pop={"type":"cat","master":"kk"}

# pets=[crzay,pop]

# print(pets)


# favorite_places={"paul":["nfu","edu","lake big"],"kk":["germany","hole","big bbbb"],"handsome":["bobs","skt2","gg1"]}

# for name,place in favorite_places.items():
#     print("person:"+name)
    
#     for pp in place:
#         print("like place :"+pp)
        


# class dog():

#     def __init__(self,name,age):
#         self.name=name
#         self.age=age

#     def sit(self):
#         print(self.name.title()+" is now sitting")

#     def roll_over(self):
#         print(self.name.title()+" rolled over!")

    
# my_dog=dog('whille',3)

# print("my dog name is "+my_dog.name.title()+".")
# print("my dog age is ",my_dog.age)

# my_dog.sit()
# my_dog.roll_over()

# print("my dod is "+str(my_dog.age)+" year old.")

# class restaurant():

#     def __init__(self,r_name,c_type):
#         self.r_name=r_name
#         self.c_type=c_type
#         self.number_reversed=0



#     def describe_restaurant(self):
#         print("this res is name:"+self.r_name)
#         print("this res is type:"+self.c_type)

#     def open_restaurant(self):
#         print("the restaurant is openning")

#     def set_number_served(self,number):
#         self.number_reversed=number
    
#     def increase_number_served(self,number):
#         self.number_reversed+=number


# class ice_cream_stand(restaurant):

#     def __init__(self,r_name,c_type):
#         super().__init__(r_name,c_type)
#         self.favors:str=""

#     def update_favors(self,fav:str):
#         self.favors:str=fav

# ice=ice_cream_stand("paul","ice")
# ice.update_favors("chocolate")
# print(ice.favors)
        

# rr=restaurant("paul","chinese")
# r2=restaurant("dona","korean")

# rr.set_number_served(32)
# rr.increase_number_served(100)
# print(rr.number_reversed)

# class Privileges():

#     def __init__(self,privileges:str="can add post"):
#         self.privileges=privileges

#     def show_privileges(self):
#         print(self.privileges)


# class user():
    
#     def __init__(self,f_name,l_name):
#         self.f_name=f_name
#         self.l_name=l_name
#         self.login_attemps=0

#     def describle(self):
#         print(self.f_name+" "+self.l_name)

#     def greet_user(self,sex:str):
#         full_name=self.f_name+" "+self.l_name
#         print("hello "+sex+" "+full_name)

#     def increment_login_attempts(self):
#         self.login_attemps+=1

#     def reset_login_attempts(self):
#         self.login_attemps=0

# class admin(user):

#     def __init__(self,f_name,l_name):
#         super().__init__(f_name,l_name)
#         self.privileges=Privileges()



    
# p1=admin("paul","lin")
# p1.privileges.privileges+=" can ban user"
# p1.privileges.show_privileges()


# p1=user("paul","lin")
# p2=user("dona","ton") 

# p1.describle()
# p2.describle()

# for i in range(0,10):       
#     p1.increment_login_attempts()

# print(p1.login_attemps)

# p1.reset_login_attempts()

# print(p1.login_attemps)


# class car():

#     def __init__(self,make,model,year):
#         self.make=make
#         self.model=model
#         self.year=year
#         self.odometer_read=0

#     def get_desciptive(self)->str:

#         long_name=str(self.make)+' '+str(self.model)+" "+str(self.year)

#         return long_name.title()
    
#     def read_odometer(self):
#         print("This car has "+str(self.odometer_read)+" miles on")

        

#     def update_odometer(self,mileage):
#         if mileage >=self.odometer_read:
#             self.odometer_read=mileage
#         else:
#             print("you can't roll back an odometer!")

#     def increment_odometer(self,miles):
#         self.odometer_read+=miles



# my_new_car=car("audi","a4",2014)
# print(my_new_car.get_desciptive())
# my_new_car.update_odometer(32)
# my_new_car.update_odometer(3)
# my_new_car.increment_odometer(100)
# my_new_car.read_odometer()

# class Battery():

#     def __init__(self,battery_size=70):
#         self.battery_size=battery_size

#     def describe_battery(self):
#         print("This car has a "+str(self.battery_size)+" -KWh battery")

#     def get_range(self):

#         if self.battery_size==70:
#             range=240

#         elif self.battery_size==85:
#             range=270

#         message="This car can go approximately "+str(range)
#         message+=" miles on a full charge"

#         print(message)

#     def update_battery(self):
#         if self.battery_size!=85:
#             self.battery_size=85

        



# class electric_car(car):
    
#     def __init__(self,make,model,year):
#         super().__init__(make,model,year)
#         self.battery=Battery()

#     # def descirble_battery(self):
#     #     print("This car has a "+str(self.battery_size)+" -KWh battery")

#     def fill_gas_tank():
#         print("This car doesn't need a gas tank!!")



# my_tesla=electric_car('tesla','model s',2016)
# print(my_tesla.get_desciptive())
# my_tesla.battery.describe_battery()
# my_tesla.battery.update_battery()
# my_tesla.battery.get_range()


# fav_language=OrderedDict()

# fav_language['jen']="python"
# fav_language['srarch']='c'
# fav_language['edward']='ruby'
# fav_language['phil']='python'

# for name,language in fav_language.items():

#     print(name.title()+" s favorite language is "+language.title()+".")




class die():

    def __init__(self,sides=6):
        self.sides=sides

    def roll_die(self):
        
        for i in range(0,10):
            x=randint(1,self.sides)
            
            print(x)
            

d=die(10)
d.roll_die()
        