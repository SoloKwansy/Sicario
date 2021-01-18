# <strong><em>Sicario</em></strong>

The code for the move prcomputation and generation is absolutely janked. When I first started, it was my first time
coding in C++ and doing an engine so it was done in an absolutely convoluted and confusing way. But... it works... and
works quite well. Plus, the time I absolutely wasted on micro-memory optimization means it uses very little memory for
the move precomputation (at the price of clarity, maintenance, my time and mental sanity), so...
</br>
</br>
<h2>Bugs/Problems</h2>
<ul>
    <li>Currently, the history array is initialised to hold 500 entries and is increased to 1000 when needed. It is
    theoretically possible that the number of moves will exceed even 1000, which would cause a segfault or stack
    smashing.</li>
    <li>In general, some of the earlier code is very messy and badly written. This will need fixing to make it more scalable
    (specifically the move generation parts).</li>
</ul>
</br>
<H2>To dos</H2>
<ul>
    <li>Improve move generation code for scalability</li>
    <li>In some terminal fonts, the name and logo does not render correctly.</li>
    <li>Need to try detect the terminal type and font type ideally.</li>
    <li>Credit the ascii art.</li>
    <li>The PV table may have collisions due to different positions having the same hash. Very unlikely but possible.
    May need some kind of check</li>
    <li>Need to separate declaration and definition of MoveList things.</li>
    <li>Currently, the king moves are generated by creating a bitboard of attackers by iterating through neighbouring
    squares. This could be improved by splitting between the cases where there are less than or greater than 8
    potential attackers left on the board.</li>
    <li>En-passant move generation may be checking invalid positions.</li>
</ul>
</br>
<H2>Acknowledgements</H2>
<strong>www.chessprogramming.org</strong> - For being my primary source of information and knowledge.</br>
<strong>Stockfish</strong> - For inspiration and guidance.</br>
<strong>Bluefeversoft</strong> - For your YouTube tutorials and explanations for concepts I found difficult to grasp.</br>
There are likely others that I have missed.</br>
</br>
And to the one who (to quote Kodaline's <em>All I Want</em>) - <em>"...brought out the best in me, a part of me I'd never seen..."</em>
