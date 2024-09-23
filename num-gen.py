import random

# Generate 2048 random numbers within the int range
numbers = random.sample(range(-2147483648, 2147483647), 2048)

# Print the numbers as a space-separated string
print(' '.join(map(str, numbers)))
