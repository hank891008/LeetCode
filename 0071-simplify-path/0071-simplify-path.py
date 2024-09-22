class Solution:
    def simplifyPath(self, path: str) -> str:
        path = re.sub("//+", "/", path).split("/")
        
        s = []
        for p in path:
            if p == '.' or p == '':
                continue
            elif p == '..':
                if len(s) > 0:
                    s.pop()
            else:
                s.append(p)
        return '/'+'/'.join(s)