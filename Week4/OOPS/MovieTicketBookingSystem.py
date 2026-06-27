class Movie:
    def __init__(self, movie_id, name, total_seats):
        self.movie_id = movie_id
        self.name = name
        self.total_seats = total_seats
        self.available_seats = total_seats

    def display(self):
        print(f"Movie ID       : {self.movie_id}")
        print(f"Movie Name     : {self.name}")
        print(f"Total Seats    : {self.total_seats}")
        print(f"Available Seats: {self.available_seats}")
        print("-" * 35)


class BookingSystem:
    def __init__(self):
        self.movies = []

    def add_movie(self):
        movie_id = int(input("Enter Movie ID: "))
        name = input("Enter Movie Name: ")
        seats = int(input("Enter Total Seats: "))

        movie = Movie(movie_id, name, seats)
        self.movies.append(movie)

        print("Movie Added Successfully!")

    def display_movies(self):
        if len(self.movies) == 0:
            print("No movies available.")
        else:
            for movie in self.movies:
                movie.display()

    def book_ticket(self):
        movie_id = int(input("Enter Movie ID: "))

        for movie in self.movies:
            if movie.movie_id == movie_id:
                tickets = int(input("Number of Tickets: "))

                if tickets <= movie.available_seats:
                    movie.available_seats -= tickets
                    print("Ticket Booked Successfully!")
                    print("Remaining Seats:", movie.available_seats)
                else:
                    print("Seats Not Available!")
                return

        print("Movie Not Found!")

    def cancel_ticket(self):
        movie_id = int(input("Enter Movie ID: "))

        for movie in self.movies:
            if movie.movie_id == movie_id:
                tickets = int(input("Number of Tickets to Cancel: "))

                if movie.available_seats + tickets <= movie.total_seats:
                    movie.available_seats += tickets
                    print("Ticket Cancelled Successfully!")
                    print("Available Seats:", movie.available_seats)
                else:
                    print("Invalid Cancellation!")
                return

        print("Movie Not Found!")


system = BookingSystem()

while True:
    print("\n========== MOVIE TICKET BOOKING ==========")
    print("1. Add Movie")
    print("2. Display Movies")
    print("3. Book Ticket")
    print("4. Cancel Ticket")
    print("5. Exit")

    choice = int(input("Enter Choice: "))

    if choice == 1:
        system.add_movie()

    elif choice == 2:
        system.display_movies()

    elif choice == 3:
        system.book_ticket()

    elif choice == 4:
        system.cancel_ticket()

    elif choice == 5:
        print("Thank You!")
        break

    else:
        print("Invalid Choice!")
