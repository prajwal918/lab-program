#a#

midf <- function(str){
  print("the number of character in a string is ")
  print(nchar(str))
  print("the String to uppercase is")
  print(toupper(str))
  n1 <- nchar(str) + 1
  print("the middle character of the String")
  mc <- substring(str, n1 %/% 2, (n1 + 1) %/% 2)
  print(mc)
}
str <- readline("enter the String")
midf(str)


#b#
is_palindrome <- function(str) {
  a <- substring(str, seq(1, nchar(str)), seq(1, nchar(str)))
  if (paste(a, sep = "", collapse = "") == paste(rev(a), sep = "", collapse = "")) {
    cat(str, " is a palindrome")
  } else {
    cat(str, " is not a palindrome")
  }
}
str <- readline("Enter a string: ")
is_palindrome(str)