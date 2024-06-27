#my own module
import webbrowser

#dictionary of the favorite sites

favorite_websites={
"facebook": "https://www.facebook.com/",
"google":  "https://www.google.com/" ,
"youtube": "https://www.youtube.com/",
"github": "https://github.com/"
}

def firefox(url):
    # open the given url in the default web browser
    webbrowser.open(url) 
