import json
import os

class Database:
    def insert(self, name, email, password):

        current_dir = os.path.dirname(os.path.abspath(__file__))
        file_path = os.path.join(current_dir, "users.json")

        with open(file_path, 'r') as rf:
            users = json.load(rf)

        if email in users:
            return 0

        users[email] = [name, password]

        with open(file_path, 'w') as wf:
            json.dump(users, wf, indent=3)

        return 1
    
    def search(self,email,password):
         current_dir = os.path.dirname(os.path.abspath(__file__))
         file_path = os.path.join(current_dir, "users.json")
         with open(file_path,'r') as rf:
            users=json.load(rf)
             
            if email in users:
                if users[email][1]==password:
                    return 1
                
                else :
                    return 0
                
            else: 
                return 0
        