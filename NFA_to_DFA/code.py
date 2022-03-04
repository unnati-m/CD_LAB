import pandas as pd
nfa = {}
n = int(input(&quot;No. of states : &quot;))
t = int(input(&quot;No. of transitions : &quot;))
for i in range(n):
    state = input(&quot;state name : &quot;)
    nfa[state] = {}
    for j in range(t):
        path = input(&quot;path : &quot;)
        print(&quot;Enter end state from state {} travelling through path {}
 : &quot;.format(state, path))
        reaching_state = [x for x in input().split()]
        nfa[state][path] = reaching_state
print(&quot;\nNFA :- \n&quot;)
print(nfa)
print(&quot;\nPrinting NFA table :- &quot;)
nfa_table = pd.DataFrame(nfa)
print(nfa_table.transpose())
print(&quot;Enter final state of NFA : &quot;)
nfa_final_state = [x for x in input().split()]
new_states_list = []
#-------------------------------------------------
dfa = {}
keys_list = list(
    list(nfa.keys())[0])
path_list = list(nfa[keys_list[0]].keys())
dfa[keys_list[0]] = {}
for y in range(t):
    var = &quot;&quot;.join(nfa[keys_list[0]][
                      path_list[y]])
    dfa[keys_list[0]][path_list[y]] = var
    if var not in keys_list:
        new_states_list.append(var)
        keys_list.append(var)
while len(new_states_list) != 0:
    dfa[new_states_list[0]] = {}
    for _ in range(len(new_states_list[0])):
        for i in range(len(path_list)):
            temp = []
            for j in range(len(new_states_list[0])):
                temp += nfa[new_states_list[0][j]][path_list[i]]
            s = &quot;&quot;

            s = s.join(temp)
            if s not in keys_list:
                new_states_list.append(s)
                keys_list.append(s)
            dfa[new_states_list[0]][path_list[i]] = s
    new_states_list.remove(new_states_list[0])
print(&quot;\nDFA :- \n&quot;)
print(dfa)
print(&quot;\nPrinting DFA table :- &quot;)
dfa_table = pd.DataFrame(dfa)
print(dfa_table.transpose())
dfa_states_list = list(dfa.keys())
dfa_final_states = []
for x in dfa_states_list:
    for i in x:
        if i in nfa_final_state:
            dfa_final_states.append(x)
            break
print(&quot;\nFinal states of the DFA are : &quot;, dfa_final_states)
