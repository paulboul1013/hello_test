class Privileges():

    def __init__(self,privileges:str="can add post"):
        self.privileges=privileges

    def show_privileges(self):
        print(self.privileges)


class user():
    
    def __init__(self,f_name,l_name):
        self.f_name=f_name
        self.l_name=l_name
        self.login_attemps=0

    def describle(self):
        print(self.f_name+" "+self.l_name)

    def greet_user(self,sex:str):
        full_name=self.f_name+" "+self.l_name
        print("hello "+sex+" "+full_name)

    def increment_login_attempts(self):
        self.login_attemps+=1

    def reset_login_attempts(self):
        self.login_attemps=0

class admin(user):

    def __init__(self,f_name,l_name):
        super().__init__(f_name,l_name)
        self.privileges=Privileges()



    
