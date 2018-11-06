#Performance Lab 3A
#Robert John Graham III
#September 6 2018

"""
   Create your own mad libs game asking the user for input to fill in 
   the blanks. Print out using .format().

   Mad Libs is a phrasal template word game where one player prompts 
   others for a list of words to substitute for blanks in a story, 
   before reading the - often comical or nonsensical - story aloud. 
   The game is frequently played as a party game or as a pastime.


    Adhere to PEP8 (Comments, formatting, style, etc)
    Create a handfull of pharses that require different numbers of inputs
    Prompt the user for input(s):
        Inputs can be done a number of ways...
            (SIMPLE) Ask user for input directly, tell them if the word(s) 
                need to be a verb, noun, etc.
            (Moderate) Give the user a handful of choices per input to 
                choose from.You will need to create a bank of verbs, nouns, 
                etc for this.
            (Harder) Give the user cards based off the actual game. 
                Allowing them to draw, etc following the rules. 
                Allow them to only input those cards.
        (Optional) Implement basic user input checking:
            Check to ensure words are words, numbers are numbers (there 
                are many ways to do this)
            Ensure symbols aren't used if they are not needed
            Check length
            etc
            Implement re-input if input is incorrect
    Output the user inputs into the given pharse
    Use formatting to not only output the user inputs, but to create a UI 
        within the terminal. Space out certain UI elements such as title of 
        program, choices, menu deceration, etc.

"""
import time
print("MAD LIBS!!!!!!")
time.sleep(3)
print("Lines will be presented that you can insert you own answers to blank"),
print("areas, creating unique and crazy scenarios.")
time.sleep(3)
print("Each line will have blanks that you will supply an answer to,"), 
print("after the line is shown.  If more words are supplied than blanks, then"), 
print("you will be prompted if you want the extra words to be discarded or if "),
print("you want to try again.")
time.sleep(3)
print("Ready?")
time.sleep(3)
#This list consists of the subject matter for each blank
pre_gen_answers = ["Last Name", "Name of Small Town", "Man's Name", "Blue Collar Job Title",
        "Relative", "Type of Accident", "Strange Occurance(1)", "Synonym for Creepy",
        "Creepy Child's Name", "Strange Occurance(2)", "Emotion", "Strange Occurance(3)", 
        "Weird Loner's Name"]
#This is the static text of the mad libs
pre_gen_text = ["The ", " family lives on a farm in ", ", Pennsylvania. ", " is a former ",
        " who lost his ", " in a ", ".  But soon a ", 
        " begins to happen.  The only other person who understands what's going on is a ",
        " child.  He and ", " being to uncover clues about the ", 
        ", and it continues to get more awkward and uncomfortable, but the child helps give him ",
        ".  The two work together to get to the bottom of the ", 
        ".  Then, when it seems unsolvable, ", 
        "(played by M. Night Shyamalan) shows up to explain what's going on."]
#User input will be stored in this map
answers = {}
blank = 0
#Each element in the static text will be displayed, followed by a ____ except for the last element
for i in pre_gen_text:
    print i,
    if blank < (len(pre_gen_text)-1):
        print("____"),
    blank += 1
blank = 0
print("\n\n")
time.sleep(3)
#Here, each subject answer will be asked for and stored
for i in pre_gen_answers:
    answers[i] = raw_input(i + ": ")
print("\n")
#The text and answers are then displayed
for i in pre_gen_text:
    print(i),
    if blank < (len(pre_gen_text)-1):
        print(answers[pre_gen_answers[blank]]),
    blank +=1
