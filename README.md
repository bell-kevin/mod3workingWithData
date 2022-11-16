# mod3workingWithData

This exercise demonstrates your competency in the skills learned in this module. You must complete this exercise on your own, without any help from an instructor or another student. If you get stuck, go back through the relevant sections in the book, the quizzes, and the assignments for this module -- everything you need to do in this exercise has been covered in this module.

These are the skills you practiced in this and previous modules and will now demonstrate:

Handling exceptions
Using STL functions
Using template functions
Using iterators
Using vectors
 

Module 3 Competency Exercise: Working with Data

Create a project that asks the user for integer and double numbers to store in vectors, then practices various STL functions and template functions.

Ask the user for 10 integers between 20 and 50. Check if the input is outside of that range and throw an exception if it is. If the data is valid, add it to the vector. After all 10 integers have been input and pushed into a vector, process it: (a) display it, (b) find and display the smallest value, (c) find and display the largest value, (d) sort the vector, (e) display the now-sorted vector, (f) calculate the average of this list of numbers.

That portion of the output (for integer numbers) would look like this:

M3 Competency

Then do the same for 10 doubles in the range of 60 to 100, which would look like this:

M3 Competency dbl

The same work happens with this vector of doubles.

You must use template functions to handle integers and doubles as needed. Use iterators as the parameters for working with the vectors. Create a template function to display a vector, and another to calculate the average (use the size() function, not the literal 10 for this calculation). Create a template function for the process (steps a - f listed above). Use a template function to check that the input is good -- return true if it's good, otherwise throw an exception that specifies if the data is too low or too high.

Note: for some of the process steps, you need an iterator for a specific location in the vector. You can't create an iterator in the template function unless the vector is passed into the function. You will be passing iterators for the beginning and end of the vector, not the vector, so you will have to create the iterator for a specific location in the main function and pass it as a parameter to the function.

The main function will ask the user for 10 integers and run the process on that vector of integers, then ask the user for 10 doubles and run the process on that vector of doubles.

Be sure to test values that are too high and too low when you run the program, as shown above. Take screenshot(s) of the result.

 

NOTE: Remember the requirements for a header and a pause at the end of the program, discussed in the reading "Console Applications". These are required in every console application project.

Submission: Submit a single zipped folder containing all of the specified screenshots AND the root folder for the project.
