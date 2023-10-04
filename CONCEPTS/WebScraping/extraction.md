


### urllib.request
- Used to open URL's
```python
from urllib.request import urlopen

#url = "http://www.hubertiming.com/results/2017GPTR10K"
url = "https://smarkets.com/"
html = urlopen(url) # Function from the urlopen module. Returns a file-like object.
```

### BeautifulSoup
- Extracts data from HTML files
- Can view the HTML of a page by using the inspect feature
```python
from bs4 import BeautifulSoup

soup = BeautifulSoup(html, 'lxml') # Create a BeautifulSoup object from the HTML
                                   # BeautifulSoup parses the raw HTML text and returns python objects
                                   # lxml is the HTML parser
                                   # BeautifulSoup function returns a soup object
type(soup) # Determines the type of an object which should be a bs4.BeautifulSoup object

title = soup.title # Can extract title
text = soup.get_text() # Text of a webpage

# Can print out only hyperlinks
all_links = soup.find_all("a")
for link in all_links:
    print(link.get("href"))

# Print the first 10 rows for sanity check
rows = soup.find_all('tr')
print(rows[:10])

# Get all the rows in list form and then convert to a dataframe
for row in rows:
    row_td = row.find_all('td')
print(row_td)
type(row_td)

# Removes HTML tags
str_cells = str(row_td)
cleantext = BeautifulSoup(str_cells, "lxml").get_text()
print(cleantext)
```