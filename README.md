Rock paper siscor program
In game.c program contains following functions:

display_character() Display the character on the matrix LED
welcome()           Display the starting massage.
game_reset()        To restart the game if the players want to play it again
select_item()       To choose the Charecter by pushing the join stick to 4 directions NORTH SOUTH WEST EAST
get_player2_state()   comfirm that another player is already chose the character then Send the character that on player to another player and recieve back. 
end_result()      compare the character that two players choose and return the result EVEN or DRAW or WIN following general Rock Paper Siscor rules

The game start when you see the massge "Start!" scrolling on the matrix LED then both players have to choose
the character that they want by move the join stick in any direction to choose 'R' 'P' or 'S', after the choose 
the character both players need press the controler to comfirm that the players have chose the character. 
Then the blue LED will turn on it means they have confirm their selection. 
The result will instantly display on the matrix LED after both players pressed confirm.

Rock paper siscor rules:
If both player have the same character the result will turn out as 'Even
If player1 chose 'R' and player2 chose 'S' then player1 is 'Win'
If player1 chose 'S' and player2 chose 'R' then player1 is 'Lose'
If player1 chose 'P' and player2 chose 'R' then player1 is 'Win'
If player1 chose 'R' and player2 chose 'P' then player1 is 'Lose'
If player1 chose 'S' and player2 chose 'P' then player1 is 'Win'
If player1 chose 'P' and player2 chose 'S' then player1 is 'Lose'
