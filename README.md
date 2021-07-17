# <strong><em>Sicario</em></strong>
Sicario is a (soon-to-be) UCI compatible chess engine. It was created as a project of mine to learn the basics of C++.
There is a lot more work to be done.
</br>
</br>
A lot of help was received by various resources online. Specifically to 
www.chessprogramming.org for explanations, Stockfish for inspiration and the Bluefeversoft YouTube channel.
</br>
</br>
</br>
<h1>Compiling and Running</h1>
Simply compile the source code with the included Makefile. The program is then run via the command `./sicario`.
</br>
</br>
</br>
<h1>Search</h1>
The search algorithm of Sicario is a vanilla monte carlo tree search algorithm. There are plans to improve this.
</br>
</br>
<h2>Selection Phase</h2>
The selection phase of the algorithm always arrives at a leaf node via a path that maximises the UCB1 value at each
level of the tree.
</br>
</br>
<h2>Expansion Phase</h2>
This phase creates a new node for each possible move from the current node position and then randomly selects one of
these expanded nodes as the current node from which to simulate a random playout.
</br>
</br>
<h2>Simulation Phase</h2>
In the simulation phase, a random playout is made by uniformly selecting and playing a move until a decisive end state
is arrived at. A value of +1 is returned if the root player wins, -1 is returned if the root player loses, and 0 is
returned in case of a draw.
</br>
</br>
<h2>Rollback Phase</h2>
With the value that the simulation phase returned, the rollback phase backpropagates this value all the way to the root
node. At each step, the value of the returned simulation value is added to the node value and the node visit count is
incremented.
</br>
</br>
</br>
<h1>Evaluation</h1>
Currently, no form of position evaluation is made.
</br>
</br>
</br>
<h1>Notes</h1>
The code for the move precomputation and generation is absolutely janked. When I first started, it was my first time
coding in C++ and doing an engine so it was done in an absolutely convoluted and confusing way. But... it works... and
works reasonably well. Plus, the time I absolutely wasted on micro-memory optimization means it uses very little memory 
for the move precomputation (at the price of clarity, maintenance, my time and mental sanity), so...
</br>
</br>
<h2>Bugs/Problems</h2>
<ul>
    <li>Currently, the history array is initialised to hold 500 entries and is increased to 1000 when needed. It is
    theoretically possible that the number of moves will exceed even 1000, which would cause a segfault or stack
    smashing.</li>
    <li>In general, some of the earlier code is very messy and badly written. This will need fixing to make it more
    scalable and modular (specifically the move generation parts).</li>
</ul>
</br>
<H2>To dos</H2>
<ul>
    <li>Improve move generation code for scalability and modularity.</li>
    <li>In some terminal fonts, the name and logo does not render correctly. Not sure if this is fixable.</li>
    <li>Need to try detect the terminal type and font type ideally. Not sure if this is even possible.</li>
    <li>The PV table may have collisions due to different positions having the same hash. Very unlikely but possible.
    May need some kind of check</li>
    <li>Need to separate declaration and definition of MoveList things.</li>
    <li>Currently, the king moves are generated by creating a bitboard of attackers by iterating through neighbouring
    squares. This could be improved by splitting between the cases where there are less than or greater than 8
    potential attackers left on the board.</li>
    <li>En-passant move generation may be checking invalid positions.</li>
    <li>Revise and update the function docstrings.</li>
    <li>Still need to implement UCI.</li>
    <li>Research into CPU architecture and their effects on the program.</li>
    <li>Utilise more in-depth C++ features.</li>
    <li>Handle exiting the program during a search and releasing the necessary memory at that point.</li>
    <li>Replace node creation of MCTS with smart pointers.</li>
</ul>
</br>
<H2>Acknowledgements</H2>
<strong>www.chessprogramming.org</strong> - For being my primary source of information and knowledge.</br>
<strong>Stockfish</strong> - For inspiration and guidance.</br>
<strong>Bluefeversoft</strong> - For your YouTube tutorials and explanations for concepts I found difficult to grasp.</br>
There are likely others that I have missed.</br>
</br>
