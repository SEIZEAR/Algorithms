class Atm:

  def __init__(self):
    self.pin = ''
    self.balance = 0
    self.menu()

  def menu(self):
    user_input = input("""
    Hi how can I help you?
    1. Press 1 to create pin
    2. Press 2 to change pin
    3. Press 3 to check balance
    4. Press 4 to withdrawl
    5. Exit
    """)

    if user_input == '1':
      self.create_pin()
    elif user_input == '2':
      self.change_pin()
    elif user_input == '3':
      self.check_balance()
    elif user_input == '4':
      self.withdraw()
    else:
      return
      

  def create_pin(self):
    user_pin = input('Enter your pin: ')
    self.pin = user_pin
    user_balance = int(input('Enter balance: '))
    self.balance = user_balance
    print('Pin created successfully!')
    self.menu()


  def change_pin(self):
    old_pin = input('Enter old pin: ')

    if old_pin == self.pin:
      new_pin = input('Enter new pin: ')
      self.pin = new_pin
      print('Pin changed successfully!')
      self.menu()

    else:
      print('Wrong Pin!!')
      self.menu()


  def check_balance(self):
    user_pin = input('Enter your pin: ')

    if user_pin == self.pin:
      print('Your balance is ',self.balance)

    else:
      print('Wrong Pin!!')
      self.menu()


  def withdraw(self):
    user_pin = input('Enter the pin: ')

    if user_pin == self.pin:
      amount = int(input('Enter the amount: '))

      if amount <= self.balance:
        self.balance = self.balance - amount
        print('Withdrawl successful. Remaining balance: ',self.balance)

      else:
        print('Not sufficient balance ')

    else:
      print('Wrong Pin!!')

    self.menu()



obj=Atm()