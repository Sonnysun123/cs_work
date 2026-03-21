def conjunction(p, q):
    return p and q

def disjunction(p, q):
    return p or q

def negation(p):
    return not p

def implication(p, q):
    return disjunction(negation(p), q)

def exclusive_or(p, q):
    return p ^ q
def biconditional(p, q):
    return p == q