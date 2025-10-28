# A # 
even_odd <- function(number)
{
  if(number %% 2 == 0)
  {
    print("The number is Even Number")
  }
  else
  {
    print("The number is Odd Number")
  }
}

print("Enter the number to be checked")
number <- scan(nlines = 1)
even_odd(number)

# B #

sqr <- function(n)
{
  print("The Square of Numbers is:")
  for(i in 0:n)
    print(i^2)
}

print("Enter the Range:")
n <- scan(nlines = 1)
sqr(n)


# C # 

srt <- function(a)
{                                                        
  v <- sort(a, decreasing = TRUE)
  print("DESCENDING ORDER")
  print(v)
  
  x <- sort(a, decreasing = FALSE)
  print("ASCENDING ORDER")
  print(x)
}

a <- scan(nlines = 6)
srt(a)
