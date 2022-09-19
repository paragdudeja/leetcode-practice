class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        groups = []
        maps = dict()
        for path in paths:
            s = path.split()
            file_count = len(s)-1
            for i in range(file_count):
                file_name, content = s[i+1].split("(")
                # content = content[:-1]
                directory = f"{s[0]}/{file_name}"
                if content in maps:
                    maps[content].append(directory)
                else:
                    maps[content] = [directory]
        
        for key in maps:
            if len(maps[key]) > 1:
                groups.append(maps[key])
        return groups