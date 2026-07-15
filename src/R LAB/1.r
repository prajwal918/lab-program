# A #
vector <- seq(5, 60, by = 5)
cat("Value of vector:", vector, "\n")
filtered_vector <- vector[vector > 15 & vector < 45]
cat("Elements greater than 15 and less than 45:", filtered_vector, "\n")

# b #
my_vector <- c(1, 2, 3, 4, 5)

my_matrix <- matrix(1:9, nrow = 3, ncol = 3)

my_nested_list <- list(
  sub_vector = c("a", "b", "c"),
  sub_number = 42
)

my_list <- list(
  vector = my_vector,
  matrix = my_matrix,
  nested_list = my_nested_list
)

for (name in names(my_list)) {
  element_class <- class(my_list[[name]])
  cat("Class of", name, ":", element_class, "\n")
}

print("Number of objects in the said list:")
print(length(my_list))

print("Length of the vector 'vector' of the said list")
print(length(my_list$vector))


# c #

matrix1 <- matrix(c(2, 1, 1, 1, 1, -1, 1, 1, 2), nrow = 3, ncol = 3) 
print(matrix1) 

matrix2 <- matrix(c(5, 2, 0, 9, 3, 4, 2, 3, 2), nrow = 3, ncol = 3) 
print(matrix2)

result <- matrix1 + matrix2 
cat("Result of addition", "\n") 
print(result)

result <- matrix1 - matrix2 
cat("Result of subtraction", "\n") 
print(result)

result <- matrix1 %*% t(matrix1) 
cat("Result of product of matrix and its transpose", "\n") 
print(result)


# d #


print("Column sum:")
colSums(matrix1)

print("Mean across rows:")
apply(matrix1, 1, mean)

print("Total sum:")
sum(matrix1)

print("Matrix elements in sorted order column wise:")
apply(matrix1, 2, sort)

