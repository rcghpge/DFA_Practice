# DFA1 {w | w starts with 0} 
# Alphabet = { 0, 1 }



def main():
    # we grab a string from the user
    var input: String = input("Please enter a string within the alphabet {0, 1}: ")

    var q0 = True
    var q1 = False
    var q2 = False
    var ERR = False


    # a for loop to iterate over each character
    for char in input:
        if char != "0" and char != "1":
            print("ERR: Language not accepted by machine")
            ERR = True
            break

        # Start State
        if q0:
            if char == "0":
                q1 =  True
            else:
                q2 = True
            
            q0 = False

        # if q1
        # since this state is accepting, and theres no where else to go we just let it eat input

        # if q2
        # rejecting state

    
    if q1 and not ERR:
        print("Yes, this language is accepted")
        return
    else:
        print("No, this language isn't accepted")
        


