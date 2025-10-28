library(dplyr)

# Create and write the first dataset (Salary)
salary = data.frame(
  ID = c(1,3,4,6,7,8,9),
  Salary = c(40754, 39040, 65043, 45000, 69000, 35020, 69500)
)
write.csv(salary, 'salary.csv', row.names = FALSE)

# Create and write the second dataset (Employee)
employee = data.frame(
  ID = c(1:7),
  Name = c('Alice', 'Bob', 'Carlo', 'John', 'Eva', 'Flora', 'George'),
  Department = c('IT', 'Tech', 'Marketing', 'Marketing', 'Tech', 'IT', 'HR'),
  Age = c(27,35,24,42,40,26,43),
  Gender = c('Female', 'Male', 'Male', 'Male', 'Female', 'Female', 'Male')
)
write.csv(employee, 'employee.csv', row.names = FALSE)

# a) Read multiple datasets
dataset1 = read.csv('salary.csv')
dataset2 = read.csv('employee.csv')

# b) Merge the datasets
merged_data = merge(dataset1, dataset2, by = 'ID')
print(merged_data)

# c) Perform aggregation
aggregated_data = merged_data %>% group_by(Gender) %>%
  summarise(
    total_salary = sum(Salary),
    mean_age = mean(Age),
    count = n()
  )
print(aggregated_data)

# d) Filter the data
filtered_data = merged_data %>% filter(Age > 25)
print(filtered_data)

# e) Create new variables
options(scipen = 999)
transformed_data <- merged_data %>%
  mutate(
    doubled_salary = Salary * 2,
    seniority = ifelse(Age > 28, "Senior", "Junior")
  )
print(transformed_data)