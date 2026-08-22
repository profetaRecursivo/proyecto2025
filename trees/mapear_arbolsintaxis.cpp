map<int, vector<int>> construirGrafo(const vector<string> &tokens) {
    map<int, vector<int>> grafo;
    stack<int> pila;
    //convierte 1 ( 2 3 ( 4 ) ) a un grafo
    for (int i = 0; i < (int)tokens.size(); i++) {
        const string &tok = tokens[i];
        if (tok == "(") continue;
        if (tok == ")") {
            if (!pila.empty()) pila.pop();
        } else {
            // asumimos que es un número
            int nodo = stoll(tok);
            if (!pila.empty()) {
                grafo[pila.top()].push_back(nodo);
            }
            pila.push(nodo);
        }
    }
    return grafo;
}
