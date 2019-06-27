Rock Paper Scissor Program
Created by Saman Ighani and Mary Hongthongkhan
The game.c program contains the following modules:

initialize_func() Set up the initial condition of helper functions
startgame()       Show the message "Move stick to start!" to let the players know that game is on
push_4direc()     To choose a Rock, Paper or Scissors by moving the joystick in either of the 4 directions: NORTH SOUTH WEST EAST
send_recieve()    Send and recieve characters from one unit to the other
compare_2P()      Compare the characters that the two players chose and return the result EVEN, DRAW or WIN following general Rock Paper Scissor rules
display_character() Display the character chosen characters or result from game on the LED matrix
game_reset()        Press the button closest to the Infrared receiever/sender and led matrix to reset variables and start a new game

The game starts when you see the message "Move stick to start!" scrolling on the matrix LED then both players choose the character that they want by moving the joystick in any direction to choose 'R' 'P' or 'S' denoting Rock, Paper or Scissors, respectively. After a character has been chosen by both players, they will then need to confirm selection by pressing down on the joystick. The blue LED will then toggle on to confirm their selection. The result for their respective selection will instantly display on the matrix LED after both players have confirmed their selection.

Rock Paper Scissor rules:
If both player have the same character the result will be 'Even'
If player1 chose 'R' and player2 chose 'S' then player1 will 'Win'
If player1 chose 'S' and player2 chose 'R' then player1 will 'Lose'
If player1 chose 'P' and player2 chose 'R' then player1 will 'Win'
If player1 chose 'R' and player2 chose 'P' then player1 will 'Lose'
If player1 chose 'S' and player2 chose 'P' then player1 will 'Win'
If player1 chose 'P' and player2 chose 'S' then player1 will 'Lose'
