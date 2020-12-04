# Fast Fourier Transform
Implementation of the fast fourier transform algorithm for multiplying large numbers.
This implementation does not use recursion which helps to save memory.
## Complexity
Time __O(log*(n))__ where n is the length of the largest number. </br>
Memory __O(n)__ where n is the length of the largest number.
## Operating modes
1. __File mode__. Consistently multiplies 2 numbers from infile. Products will be write to outfile. If outfile doesn\`t exist, program creates it </br>
`> fft_multiply.exe -f infile.txt outfile.txt`
2. __Console mode__. Multiplies 2 arguments. Product will print in standart out stream. </br>
`> fft_multiply.exe -m first_number second_number`
