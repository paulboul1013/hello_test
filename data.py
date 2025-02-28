import matplotlib.pyplot as plt
from random import choice
from random import randint
import pygal

# input_values=[1,2,3,4,5]
# squares=[1,4,9,16,25]

# plt.plot(input_values,squares,linewidth=5)

# plt.title("square ,numbers",fontsize=24)
# plt.xlabel("value",fontsize=14)
# plt.ylabel("square  of value",fontsize=14)
# plt.tick_params(axis='both',labelsize=14) #刻度大小
# plt.show()


# plt.scatter(input_values,squares,s=100)
# plt.title("square ,numbers",fontsize=24)
# plt.xlabel("value",fontsize=14)
# plt.ylabel("square  of value",fontsize=14)
# plt.tick_params(axis='both',which='major',labelsize=14)
# plt.show()


# x_values=list(range(1,1001))
# y_values=[x**2 for x in x_values]

# plt.scatter(x_values,y_values,s=40,cmap=plt.cm.Blues,edgecolors='none',c=y_values)

# plt.axis([0,1100,0,1100000])
# # plt.show()
# plt.savefig('squares_plot.png',bbox_inches='tight')

# x_values=list(range(1,5001))
# y_values=[x**3 for x in x_values]

# # plt.plot(x_values[:5],y_values[:5])
# # plt.plot(x_values,y_values)
# plt.scatter(x_values,y_values,s=40,cmap=plt.cm.Blues,edgecolors='none',c=y_values)
# plt.tick_params(axis='both',labelsize=14) 
# plt.show()


# class randomwalk():

#     def __init__(self,num_points=5000):
#             self.num_points=num_points
#             self.x_values=[0]
#             self.y_values=[0]

    
        

#     def fill_walk(self):
          
#         while len(self.x_values) <self.num_points:
#             x_direction=choice([1,-1])
#             x_distance=choice([1,2,3,4,5,6])
#             x_step=x_direction*x_distance
   
#             y_direction=choice([1,-1])
#             y_distance=choice([1,2,3,4,5,6])
#             y_step=y_direction*y_distance
           
#             if x_step==0 and y_step==0:
#                  continue

    
#             next_x=self.x_values[-1]+x_step
#             self.x_values.append(next_x)

#             next_y=self.y_values[-1]+y_step
#             self.y_values.append(next_y)


# while True:
                
#     rw=randomwalk()
#     rw.fill_walk()
#     # plt.scatter(rw.x_values,rw.y_values,s=15)
    
#     plt.figure(dpi=128,figsize=(10,6))


#     ponint_numbers=list(range(rw.num_points))
#     plt.scatter(rw.x_values,rw.y_values,c=ponint_numbers,cmap=plt.cm.Blues,edgecolors='none',s=20)

#     plt.scatter(0,0,c='green',edgecolors='none',s=100)
#     plt.scatter(rw.x_values[-1],rw.y_values[-1],c='red',edgecolors='none',s=100)

#     # 隱藏坐標軸
#     # plt.axes().get_xaxis().set_visible(True)
#     # plt.axes().get_yaxis().set_visible(True)


#     plt.show()

#     keep_running=input("make another walk (y/n):")
#     if keep_running=='n':
#          break


class die():

    def __init__(self,num_sides=6):

        self.num_sides=num_sides

    def roll(self):
        return randint(1,self.num_sides)
    

d1=die()
d2=die()
# d3=die()

results=[]
for roll_num in range(5000):
    result=d1.roll()*d2.roll()
    results.append(result)

# print(results)

freq=[]
# max_results=d1.num_sides+d2.num_sides
max_results_mulpty=d1.num_sides*d2.num_sides

for value in range(1,max_results_mulpty+1):
    f=results.count(value)
    freq.append(f)

# print(freq)

hist=pygal.Bar()
hist.title="Results of rolling three D6  1000 times."
hist.x_labels=[x for x in range(1,36)]
# hist.x_labels=['2','3','4','5','6','7','8','9','10','11','12','13','14','15','16']
hist.x_title="Result"
hist.y_title="Frequency of Result"

hist.add('D6'+'D6',freq)
hist.render_to_file("die_visual.svg")


