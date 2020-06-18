def transitive_closure(a):
    closure = set(a)
    while True:
        new_relations = set((x,w) for x,y in closure for q,w in closure if q == y)

        closure_until_now = closure | new_relations

        if closure_until_now == closure:
            break

        closure = closure_until_now

    return closure

print(transitive_closure([(1,2), (1,3), (1,4), (2,4), (2,3), (3,4), (4,4)]))
