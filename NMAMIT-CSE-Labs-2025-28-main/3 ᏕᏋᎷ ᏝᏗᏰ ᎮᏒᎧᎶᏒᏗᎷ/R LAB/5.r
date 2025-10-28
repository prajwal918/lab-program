library(dplyr)
library(ggplot2)
library(tidyr)

file_path <- "train.csv"
data <- read.csv(file_path)

summary_stats <- summary(data)
print(summary_stats)

print(ggplot(data, aes(x = Age)) +
        geom_histogram(binwidth = 5, fill = "blue", color = "black") +
        labs(title = "Distribution of Age on Titanic",
             x = "Age",
             y = "Frequency"))

missing_values <- colSums(is.na(data))
print(missing_values)

#b

data <- distinct(data)



data$Age[is.na(data$Age)] <- mean(data$Age, na.rm = TRUE)
missing_values <- colSums(is.na(data))
print(missing_values)

#c


adult_passengers <- filter(data, Age > 18)

sorted_titanic <- arrange(data, desc(Fare))

A <- data.frame(
  PassengerId = c(2, 4, 6, 10),
  CountryOfOrigin = c("USA", "UK", "Canada", "USA"),
  IsStaff = c(FALSE, FALSE, TRUE, FALSE)
)

print(colnames(data))
print(colnames(A))

merged_data <- merge(data, A, by.x = "PassengerId", by.y = "PassengerId")
print(merged_data)


#d


print(ggplot(data, aes(x = Age, fill = factor(Survived, levels = c(0,1)))) +
        geom_histogram(binwidth = 5, color = "black") + 
        labs(title = "Age vs Survived",
             x = "Age", 
             y = "Survived count", 
             fill = "Survived") + 
        scale_fill_manual(values = c("0" = "red", "1" = "blue")))


t_test_result <- t.test(Age ~ Survived, data = data)
print(t_test_result)

correlation_coefficient <- cor(data$Age, data$Fare)
print(correlation_coefficient)


print(ggplot(data, aes(x = factor(Survived), fill = factor(Survived))) +
        geom_bar() +
        labs(title = "Number of Survivors on Titanic",
             x = "Survived",
             y = "Count") +
        scale_fill_manual(values = c("red", "green")))
