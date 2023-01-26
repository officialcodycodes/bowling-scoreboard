# bowling-scoreboard
Obtain the user's name, and allow the user to play simulated bowling using arrays and random numbers.

--------------
THE SITUATION:
--------------
  I am trying to get the user’s name, and to allow the user to play simulated bowling using arrays and random numbers on a range from 0-10 (how many pins are on the lane).  The user will go through 10 frames (10 attempts), and in each frame, the user will have two rolls, but there are exceptions.  In the case of frames 1-9, if the user knocks down 10 pins in the first roll, they will not have a second roll for that frame.  In general, in the second roll of frames 1-9, the user can only knock down a range of 0 pins to however many pins are remaining after the first roll.  If the user knocks down 10 pins in 2 rolls, then the program will output a message to the user indicating they scored a spare.  If the user knocks down 0 pins in any roll in a frame, the program will output a message to the user indicating that they scored a gutter ball.  Additionally, if the user scores a strike in frame 10, then they will receive a 3rd roll/chance for that frame.

  To implement scoring, we should use an array.  The array should be listed as scores, and as the user goes through the process of bowling, then we will add scores to the array accordingly.  Essentially, the user will get 2 rolls per frame, and the score will be added to the array respectively.  In the event that the user scores a strike, then the frame will end and the next frame will begin.  Once the second frame ends (two rolls), the score from the second frame will be added to the first frame (10 from the strike), and that sum will be frame 1’s score.  The second frame will have the score of its two rolls in frame 2.  Essentially, if the user scores a strike, then it will add the next two rolls to its frame’s score.  This same principle applies to a spare.  If the user scores a spare, then it will add the NEXT roll to its frame’s score.  So, a strike will look ahead by 2 rolls.  A spare will look ahead by one roll.  Generally, the score for each roll will be determined by a random number generated in a range from 0-10, or a range with exceptions discussed above.

  All of the scoring will use arrays to add.  I am planning to make one array that contains each frame’s score (size 10) and then subarrays for the two rolls of each frame.  I am assuming that there will only be one player and that the user will complete every game they start.  The one user input will be his name.  While the user will enter an input to roll the bowling ball, that input will be disregarded by using cin.ignore().  The outputs of this program will be a greeting, an indicator to roll, a scoreboard, messages that are dependent on what kind of score the user gets for a roll (strike, spares, etc.), and the total score at the end of the match.

--------------
THE MAIN GOALS:
--------------
- Ask the user for their name, and then send a greeting with that user input
- Tell the user it is frame 1 and that they need to press enter to continue (cin.ignore())
      - For each frame (in other words, attempt), there are 2 rolls
          - There are 10 frames in total
      - In the first roll of frame 1, the user can knock down 0-10 pins
          - If the user knocks down 10 pins in the FIRST roll, it is a strike(X)
              - User will not be allowed to have a second roll in that frame if they get a strike
      - In the second roll, the user can knock down 0 to however many pins remain after the first roll
          - If the user knocks down 10 pins USING 2 rolls, it is a spare(/)
      - If the user knocks down 0 pins in ANY roll, it is a gutter(-) ball
- Repeat the frame process 9 more times (so the user goes through 10 frames total)
- 10th frame
    - If the user scores a STRIKE or SPARE, then the user gets a 3rd roll (ONLY IN THE 10TH FRAME).
- Calculate total frame score at the end (sum of all frame scores).
