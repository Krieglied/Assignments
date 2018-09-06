#Performance Lab 2H
#Robert John Graham III
#September 6 2018

""" 
   Create a program that takes input of a group of students' names 
   and grades... then sorts them based on highest to lowest grade. 
   Then calculate and print the sorted list and the average for 
   the class. (Hint: Use Dictionaries!)
"""
import sys
#This function error checks to make that the grade input
#Is of int type.  The function will continue to run
#Until a value of the correct type is input
def read_input():
    capture = raw_input("Please enter in a student's grade: ")
    try:
        capture = int(capture)
    except ValueError:
       print "Please enter an int into grade."
       capture = read_input()
    return capture


#The list of students will be a dictionary, with the name as the key
#And the list of grades as the value
students_list = {}
#This is a do while loop that will continue until user doesn't
#Want to input students any longer
while True:
    student_name = raw_input("Please enter in a student's name: ")
    student_grades = []
    while True:
        #Here, error checking needs to happen so that only ints
        #are put into grade
        grade = read_input()
        #The grade received is input into a list of grades
        student_grades.append(grade)
        moreGrades = raw_input(
                "Would you like to add another grade for the student (Y or N)?"
                ).upper()
        #Here, the user is prompted if there are more grades to be input
        if moreGrades != "Y":
            break
        #Once all the grades are received, the list is sorted
        student_grades.sort()
    #Once the grades are done, the student and his/her grades is put
    #Into the dictionary
    students_list[student_name] = student_grades
    moreStudents = raw_input(
            "Would you like to add another student '(Y or N)?"
            ).upper()
    #User is prompted if there are more students to be input
    if moreStudents != "Y":
        break
#Here, the list of students is outputted
print "\n\nThe students in the class:"
for i in students_list.keys():
    print i
#The grades for each student is then outputted
print "\n\nAll grades in the class:"
for i in students_list.values():
    print i
print "\n\nThe average of the class:"
#The average is computed from each individual grade
average, amount_of_grades = 0,0
for i in students_list.values():
    for j in i:
        average += int(j)
        amount_of_grades += 1
average = average / amount_of_grades
print "{0:.2f}".format(average)
