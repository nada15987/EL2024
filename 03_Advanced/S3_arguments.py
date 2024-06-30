import sys

# Display the name of the script
print(f"The program name used to launch me is {sys.argv[0]}.")
#Number of arguments
print("Number of arguments:", len(sys.argv))
## Display the Argument List:
print("I was passed the following arguments:")
for arg in sys.argv[1:]:
  print(arg)
