-5
 Repeated node check is assumed, so expanded nodes did not add already
expanded nodes. This is done partially incorrectly as well, in the case
of node B expansion.

-5 Goal check performed during node E expansion, not when E is added to fringe.

-5 Above error leads to addition of second C node to expansion list, which is incorrect.
