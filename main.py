def can_cut_rectangles(n: int, rectangles: list[list[int]]) -> bool:
    """
    Determines if it is possible to make either two horizontal or two vertical cuts on the grid
    such that each of the three resulting sections formed by the cuts contains at least one rectangle,
    and every rectangle belongs to exactly one section.

    Args:
        n: The dimensions of the n x n grid.
        rectangles: A 2D array of coordinates representing rectangles on the grid.

    Returns:
        True if such cuts can be made; otherwise, False.
    """

    def check_cuts(cuts, horizontal):
        sections = [[] for _ in range(3)]
        
        for rect in rectangles:
            startx, starty, endx, endy = rect
            
            if horizontal:
                if endy <= cuts[0]:
                    sections[0].append(rect)
                elif endy <= cuts[1]:
                    sections[1].append(rect)
                else:
                    sections[2].append(rect)
            else:
                if endx <= cuts[0]:
                    sections[0].append(rect)
                elif endx <= cuts[1]:
                    sections[1].append(rect)
                else:
                    sections[2].append(rect)
        
        return all(sections)
    
    # Check horizontal cuts
    for i in range(1, n - 1):
        for j in range(i + 1, n):
            if check_cuts([i, j], True):
                return True
    
    # Check vertical cuts
    for i in range(1, n - 1):
        for j in range(i + 1, n):
            if check_cuts([i, j], False):
                return True
    
    return False

# Test the example
n = 5
rectangles = [[1,0,5,2], [0,2,2,4], [3,2,5,3], [0,4,4,5]]
print(can_cut_rectangles(n, rectangles))  # Should print: True