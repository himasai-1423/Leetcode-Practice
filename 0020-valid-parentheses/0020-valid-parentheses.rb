# @param {String} s
# @return {Boolean}
def is_valid(s)
    m = {
        '(' => -1,
        '{' => -2,
        '[' => -3,
        ')' => 1,
        '}' => 2,
        ']' => 3
    }
    st = []
    s.each_char do |ch|
        if m[ch] < 0
            st.push(ch)
        else
            if st.empty?
                return false
            end
            top = st.pop()
            if m[top] + m[ch] != 0
                return false
            end
        end
    end
    st.empty?
end
