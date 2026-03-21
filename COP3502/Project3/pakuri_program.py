from pakuri import *
from pakudex import *

if __name__ == '__main__':
    print("Welcome to Pakudex: Tracker Extraordinaire!")
    while True:
        try:
            capacity = int(input("Enter max capacity of the Pakudex: "))
            assert capacity >= 0, "Please enter a valid size."
            break
        except ValueError:
            print("Please enter a valid size.")
        except AssertionError as e:
            print(e)
    print(f"The Pakudex can hold {capacity} species of Pakuri.")
    my_store = Pakudex(capacity)
    while True:
        try:
            print()
            print("Pakudex Main Menu",
                  "-----------------",
                  "1. List Pakuri",
                  "2. Show Pakuri",
                  "3. Add Pakuri",
                  "4. Evolve Pakuri",
                  "5. Sort Pakuri",
                  "6. Exit",
                  sep ="\n", end ="")
            print()
            choice = int(input("What would you like to do? "))
            assert 1 <= choice <= 6
            if choice == 1:
                species_names = my_store.get_species_array()
                if species_names is None:
                    print("No Pakuri in Pakudex yet!")
                else:
                    print("Pakuri In Pakudex:")
                    count = 1
                    for species in species_names:
                        print(f"{count}. {species}")
                        count += 1
            elif choice == 2:
                species = input("Enter the name of the species to display: ")
                status = my_store.get_stats(species)
                if status is None:
                   print("Error: No such Pakuri!")
                else:
                    print()
                    print(f"Species: {species}")
                    print(f"Attack: {status[0]}")
                    print(f"Defense: {status[1]}")
                    print(f"Speed: {status[2]}")
            elif choice == 3:
                if my_store.get_size() == my_store.get_capacity():
                    print("Error: Pakudex is full! ")
                else:
                    species = input("Enter the name of the species to add: ")
                    a = my_store.add_pakuri(species)
                    if a is False:
                        print("Error: Pakudex already contains this species!")
                    else:
                        print(f"Pakuri species {species} successfully added!")
            elif choice == 4:
                try:
                    species = input("Enter the name of the species to evolve: ")
                    a = my_store.evolve_species(species)
                    if a:
                        print(f"{species} has evolved!")
                    else:
                        print("Error: No such Pakuri!")
                except:
                    print("unkown")
            elif choice == 5:
                my_store.sort_pakuri()
                print("Pakuri have been sorted!")
            elif choice == 6:
                break
        except ValueError:
            print("Unrecognized menu selection!")
        except AssertionError:
            print("Unrecognized menu selection!")


    print("Thanks for using Pakudex! Bye!")