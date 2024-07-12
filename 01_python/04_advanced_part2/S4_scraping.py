#beautiful soup
import requests
from bs4 import BeautifulSoup
import csv

date = input("please eneter a date in the following form MM/DD/YYYY ")
page = requests.get(f"https://www.yallakora.com/match-center/?date={date}")

def main(page):

    src = page.content   # the whole content of the page is included in src
    soup = BeautifulSoup(src , "lxml")  # the content is written in a similar way that in the site itself 
                                        # lxml is the fastest parser
    matched_details = [] # list of dictionaries

    championships = soup.find_all("div" ,{'class': 'matchCard'})  # all the found championships
    
    def get_match_info(championships):   

        championship_title = championships.contents[1].find("h2").text.strip()
        all_matches = championships.contents[3].find_all("div" ,{'class': 'liItem'})  #num of matches in each championship
        number_of_matches= len(all_matches) 
        
        #loop throught number of matches of each championship
        for i in range (number_of_matches):
            #get teams names
            team_A = all_matches[i].find("div",{'class':'teamA'}).text.strip()
            team_B = all_matches[i].find("div",{'class':'teamB'}).text.strip()

            #get score
            match_result = all_matches[i].find("div",{'class':'MResult'}).find_all('span', {'class':'score'})  # all spans in MResult class
            score = f"{match_result[0].text.strip()} - {match_result[1].text.strip()}"

            #get time
            match_time = all_matches[i].find("div",{'class':'MResult'}).find('span',{'class':'time'}).text.strip()

            # add match info to matches_Details
            matched_details.append({"نوع البطولة" : championship_title ,
                                    "الفريق الأول " : team_A ,
                                    "الفريق الثانى ": team_B,
                                    "ميعاد المباراة ": match_time ,
                                    "النتيجة ": score })
            
            


            
    for i in range (len(championships)):
        get_match_info(championships[i]) 

    #creating csv file
    keys = matched_details[0].keys()

    with open ('/home/nada-tharwat/Documents/my_python/matches_datails.csv','w') as output_file: #aliasing
        dict_writer = csv.DictWriter(output_file,keys)
        dict_writer.writeheader()
        dict_writer.writerows(matched_details)
        print("file is created")
    
    reader = csv.reader(open('/home/nada-tharwat/Documents/my_python/matches_datails.csv','r'))
    print(reader)
    for line in reader:
        print(line)

        

main(page)