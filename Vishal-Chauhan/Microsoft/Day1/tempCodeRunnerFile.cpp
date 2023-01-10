string op = st.top();
                st.pop();
                int cal = operation(stoi(f), stoi(s), op[0]);
                st.push(to_string(cal));