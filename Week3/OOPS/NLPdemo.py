import nlpcloud

class NLPApp:
  
  def __init__(self):
    self.__database={}
    self.__first_menu()
     
  def __first_menu(self):
    first_input=input("""
    Hi! how would you like to proceed?
    1. Not a member? Register
    2. Already a member? Login
    3. Exit
    """)

    if first_input=='1':
      self.__register()
    if first_input=='2':
      self.__login()
    if first_input=='3':
      return
    else:
      return 

  def __second_menu(self):
    second_input=input("""
    Hi! how would you like to proceed?
    1. NER
    2. Language Detection
    3. Sentiment Analysis
    4. Logout
    """)

    if second_input=='1':
      self.__ner()
    if second_input=='2':
      self.__language_detection()
    if second_input=='3':
      self.__sentiment_analysis()
    if second_input=='4':
      return
    else:
      return


  def __register(self):
    name=input("Enter Name: ")
    email=input("Enter Email: ")
    password=input("Enter Password: ")

    if email in self.__database:
       print("Email already exist!")
    else:
      self.__database[email]=[name,password]
      print("Registration Successful! Now Login ")
      self.__first_menu()

  def __login(self):
    email=input("Enter Email: ")
    password=input("Enter Password: ")

    if email in self.__database:
      if self.__database[email][1]==password:
        print("Login Successful!")
        self.__second_menu()
      else :
        print("Wrong Password ")
        self.__login()
    else:
      print("This email is not Registered!!")
      self.__first_menu()

  def __ner(self):
    para=input("Enter the paragraph: ")
    search_term=input("What would you like to search: ")

    client = nlpcloud.Client("gpt-oss-120b", "9635201b6d2b9849366b2b4c157f8eb9900716ff", gpu=True)
    response=client.entities(para,searched_entity=search_term)
      
    print(response)

  def __sentiment_analysis(self):
    para=input("Enter the paragraph: ")
    

    client = nlpcloud.Client("gpt-oss-120b", "9635201b6d2b9849366b2b4c157f8eb9900716ff", gpu=True)
    response=client.sentiment(para)

    L=[]
    for i in response['scored_labels']:
      L.append(i['score'])

    index=sorted(list(enumerate(L)),key = lambda x:x[1],reverse=True)[0][0]
    print(response['scored_labels'][index]['label'])   
   
    self.__second_menu()
    
obj=NLPApp()