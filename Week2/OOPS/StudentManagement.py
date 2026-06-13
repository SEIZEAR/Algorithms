class Student:

    def __init__(self, roll_no, name, marks):
        self.roll_no = roll_no
        self.name = name
        self.marks = marks

    def display(self):
        print(f"Roll No : {self.roll_no}")
        print(f"Name    : {self.name}")
        print(f"Marks   : {self.marks}")
        print("-" * 20)


class StudentManagementSystem:

    def __init__(self):
        self.students = []

    def add_student(self):
        roll = int(input("Enter Roll No: "))
        name = input("Enter Name: ")
        marks = float(input("Enter Marks: "))

        student = Student(roll, name, marks)
        self.students.append(student)

        print("Student Added Successfully!")

    def view_students(self):
        if not self.students:
            print("No Students Found!")
            return

        for student in self.students:
            student.display()

    def search_student(self):
        roll = int(input("Enter Roll No to Search: "))

        for student in self.students:
            if student.roll_no == roll:
                student.display()
                return

        print("Student Not Found!")

    def delete_student(self):
        roll = int(input("Enter Roll No to Delete: "))

        for student in self.students:
            if student.roll_no == roll:
                self.students.remove(student)
                print("Student Deleted Successfully!")
                return

        print("Student Not Found!")

    def average_marks(self):
        if not self.students:
            print("No Students Available!")
            return

        total = 0

        for student in self.students:
            total += student.marks

        avg = total / len(self.students)

        print("Average Marks =", avg)


sms = StudentManagementSystem()

while True:

    print("\n===== STUDENT MANAGEMENT SYSTEM =====")
    print("1. Add Student")
    print("2. View Students")
    print("3. Search Student")
    print("4. Delete Student")
    print("5. Average Marks")
    print("6. Exit")

    choice = input("Enter Choice: ")

    if choice == "1":
        sms.add_student()

    elif choice == "2":
        sms.view_students()

    elif choice == "3":
        sms.search_student()

    elif choice == "4":
        sms.delete_student()

    elif choice == "5":
        sms.average_marks()

    elif choice == "6":
        print("Thank You!")
        break

    else:
        print("Invalid Choice!")
