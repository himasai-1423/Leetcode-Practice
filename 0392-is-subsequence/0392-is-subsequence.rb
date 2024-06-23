# @param {String} s
# @param {String} t
# @return {Boolean}
def is_subsequence(s, t)
    j = 0
    
    t.each_char do |i| 
        if j >= s.length 
            break
        end
        
        if i == s[j]
            j += 1
        end
    end
    
    puts j
    
    s.length == j
end