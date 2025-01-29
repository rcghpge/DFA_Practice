#!/usr/bin/env mojo
# DFA_2  {w | w begins with 1 ends with 0 }
# q0 = start state
# q2 = accepting state

def main():
  print("Alphabet = {0, 1)")
  var input: String = input("Please enter a string: ")

  # States
  var q0 = True
  var q1 = False
  var q2 = False
  var q3 = False
  var ERR = False

  for char in input:
    if char != "0" and char != "1":
      print("ERR: Lang not accepted by machine")
      ERR = True
      break

    # start
    if q0:
      if char == "1":
        q1 = True
      else:
        q3 = True
      
      q0 = False
   
    if q1:
      if char == "1":
        q1 = True
      else:
        q1 = False
        q2 = True

    if q2:
      # check again if it ends w/ 0
      if char == "1":
        q2 = False
        q1 = True
      # we end with 0

    # sink state if q3:


  if q2 and not ERR:
    print("Yes, this language is accepted")
    return
  else:
    print("No, this language isn't accepted")
