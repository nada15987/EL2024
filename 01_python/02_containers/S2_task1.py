
#task1

#1-Make your module that contain favourite websites and have function called Firefox take url and open website
#2- then make main file and print menu of sites for user and let him choice

import S2_favorites

def print_menu():
    print("the list of the favorite sites is: ")
    for name , url in S2_favorites.favorite_websites.items():
        print(f"{name}:{url}")


def main():
    print_menu()

    choice= input(" enter the name of the wanted website ")
    if choice in S2_favorites.favorite_websites:
        S2_favorites.firefox(S2_favorites.favorite_websites[choice])
    else:
        print("invalid choice")

main()

