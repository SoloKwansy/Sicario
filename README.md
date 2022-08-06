# <strong><em>Sicario</em></strong>
Sicario is a (soon-to-be) Uci compatible chess engine. It was created as a project of mine to learn the basics of C++.
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
<h2>Supported commands</h2>
<ul>
    <li>UCI protocol commands</li>
    <li><code>perft [depth]</code> where <code>depth</code> is the desired depth.</li>
</ul>
</br>
<h1>Move generation</h1>
Move generation is pseudo-legal and based on magic bitboards. For non-ranged pieces, you can just index into an array to get the appropriate move set. For ranged pieces, a slightly unconventional approach was used to avoid wasting large amounts of memory.
</br>
</br>
For a ranged piece like a rook on A4, one will need to take the masked occupancy of the position along the A file and 4th rank (excluding the rook itself) to produce a new bitboard. One must then multiply this bitboard by the corresponding rook magic number for A4, and then shift the result down by the corresponding shift. The resulting number will be unique for every possible occupancy. However, we ideally want to map attack ranges to attack sets, not occupancies to attack sets as the majority of attack sets will be duplicated by different occupancies since only the first blocking piece determines the attack range and not the ones behind it. Therefore, this unique number we get after the shift, will be the index into another precomputed data structure, that gives us a unique mapping from attack range to attack sets by construction.
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
    <li>Still need to implement Uci.</li>
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

TODO three fold repitition bug
TODO CHeck fullmove increment is occurring at right time
TODO draw by insufficient material