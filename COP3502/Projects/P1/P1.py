import p1_random as p1
rng=p1.P1Random()

game_num=0
player_win=0
dealer_win=0
game_ties=0
in_progress=True
while in_progress:
    #new game loop
    game_num+=1
    print(f"START GAME #{game_num}\n")
    card=rng.next_int(13)+1 #[0,12]+1
    if 2<=card<=10:
        hand=card
    elif card==1:
        hand=card
        card="ACE"
    elif card==11:
        hand=10
        card="JACK"
    elif card==12:
        hand=10
        card="QUEEN"
    elif card==13:
        hand=10
        card="KING"
    print(f'Your card is a {card}!')
    print(f"Your hand is: {hand}\n")

    while True:
        choice=int(input("1. Get another card\n2. Hold hand\n3. Print statistics\n4. Exit\n\nChoose an option: "))
        print()
        if choice==1:
            card=rng.next_int(13)+1
            if card ==1:
                hand +=1
                print(f'Your card is a ACE!')
                print(f"Your hand is: {hand}\n")
            elif 2<=card<=10:
                hand += card
                print(f'Your card is a {card}!')
                print(f"Your hand is: {hand}\n")
            elif card==11:
                hand += 10
                print(f'Your card is a JACK!')
                print(f"Your hand is: {hand}\n")
            elif card == 12:
                hand += 10
                print(f'Your card is a QUEEN!')
                print(f"Your hand is: {hand}\n")
            elif card == 13:
                hand += 10
                print(f'Your card is a KING!')
                print(f"Your hand is: {hand}\n")
            if hand==21:
                player_win +=1
                print("BLACKJACK! You win!\n")
                break
            elif hand>21:
                dealer_win +=1
                print("You exceeded 21! You lose.\n")
                break

        elif choice==2:
            #dealer's draw
            dealer_hand=rng.next_int(11)+16
            print(f"Dealer's hand: {dealer_hand}")
            print(f"Your hand is: {hand}\n")
            if dealer_hand == 21:
                dealer_win += 1
                print("Dealer wins!\n")
                break
            elif dealer_hand > 21:
                player_win += 1
                print("You win!\n")
                break
            elif hand==dealer_hand:
                print("It's a tie! No one wins!\n")
                game_ties += 1
                break
            elif hand>dealer_hand:
                player_win += 1
                print("You win!\n")
                break
            elif dealer_hand>hand:
                dealer_win += 1
                print("Dealer wins!\n")
                break
        elif choice==3:
            print(f"Number of Player wins: {player_win}")
            print(f"Number of Dealer wins: {dealer_win}")
            print(f"Number of tie games: {game_ties}")
            print(f"Total # of games played is: {game_num-1}")
            print(f"Percentage of Player wins: {player_win / (game_num-1) * 100:.1f}%\n")
        elif choice==4:
            in_progress=False
            break
        else:
            print("Invalid input!\n\nPlease enter an integer value between 1 and 4.")