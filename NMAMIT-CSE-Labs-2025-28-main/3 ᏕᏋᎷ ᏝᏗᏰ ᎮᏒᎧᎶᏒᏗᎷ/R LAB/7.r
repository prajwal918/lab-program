library(rvest)

# a) Define the target website
url <- "http://books.toscrape.com/"

# b) Retrieve the HTML content
html_content <- read_html(url)
print(html_content)

# c) Parse and extract the desired data using XPath selectors
title_xpath <- '//*[@class="product_pod"]/h3/a'
# This line has been updated to match your lab notes exactly.
price_xpath <- '//*[@class="product_pod"]/div[2]/p[1]'

titles <- html_content %>% html_nodes(xpath = title_xpath) %>%
  html_text()
print(titles)

prices <- html_content %>% html_nodes(xpath = price_xpath) %>%
  html_text()
print(prices)

# Combine into a data frame
book_data <- data.frame(
  Title = titles,
  Price = prices
)

# d) Save the extracted data to a file
write.csv(book_data, "books.csv", row.names = FALSE)