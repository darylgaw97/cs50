import cs50


text = cs50.get_string("Text: ")
# counting number of letters in text
letters = 0
for c in text:
    if c.isalpha():
        letters += 1
        
# counting number of words
words = 1
for c in text:
    if c == " ":
        words += 1
        
# counting numbers of sentences
sentences = 0
for c in text:
    if c == "." or c == "!" or c == "?":
        sentences += 1
        
# calculating Coleman-Liau index
L = letters * (100 / words)
S = sentences * (100 / words)
index = 0.0588 * L - 0.296 * S - 15.8
grade = round(index)
if grade <= 0:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(grade))
