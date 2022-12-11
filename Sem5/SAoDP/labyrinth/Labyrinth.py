import pygame
import time
from math import inf
from PriorityQueue import AStarQueue, PriorityQueue
import random
from collections import deque

# Define some colors
import ColorSettings

# For creating Buttons
from Button import Button

# Make it easier to add different node types
from Node import Node

# This sets the WIDTH and HEIGHT of each grid location
WIDTH = 7
HEIGHT = WIDTH  # so they are squares
BUTTON_HEIGHT = 50

# This sets the margin between each cell
MARGIN = 0

# Create a 2 dimensional array (a list of lists)
grid = []
print("Enter number of rows (rows = columns) / N and M for Labyrinth")
print("Enter ->")
ROWS = int(input())
# Iterate through every row and column, adding blank nodes
for row in range(ROWS):
    grid.append([])
    for column in range(ROWS):
        grid[row].append(Node('blank'))

    # Set start and end points for the pathfinder
START_POINT = (random.randrange(2, ROWS - 1, 2) - 1, random.randrange(2, ROWS - 1, 2) - 1)
END_POINT = (random.randrange(2, ROWS - 1, 2), random.randrange(2, ROWS - 1, 2))

grid[START_POINT[0]][START_POINT[1]].update(nodetype='start')
grid[END_POINT[0]][END_POINT[1]].update(nodetype='end')

DIAGONALS = False
VISUALISE = True

# Used for handling click & drag
mouse_drag = False
drag_start_point = False
drag_end_point = False

# Used for deciding what to do in different situations
path_found = False
algorithm_run = False

pygame.init()

# Set default font for nodes
FONT = pygame.font.SysFont('arial', 6)

# Set the width and height of the screen [width, height]
SCREEN_WIDTH = ROWS * (WIDTH + MARGIN) + MARGIN * 2
SCREEN_HEIGHT = SCREEN_WIDTH + BUTTON_HEIGHT * 3
WINDOW_SIZE = (SCREEN_WIDTH, SCREEN_HEIGHT)
screen = pygame.display.set_mode(WINDOW_SIZE)

# Make some Buttons
dijkstraButton = Button(ColorSettings.GREY, 0, SCREEN_WIDTH, SCREEN_WIDTH / 3, BUTTON_HEIGHT,
                        "Dijkstra (=BFS when constant distances)")
resetButton = Button(ColorSettings.GREY, SCREEN_WIDTH / 3, SCREEN_WIDTH, SCREEN_WIDTH / 3, BUTTON_HEIGHT * 2, "Reset")
mazeButton = Button(ColorSettings.GREY, (SCREEN_WIDTH / 3) * 2, SCREEN_WIDTH, SCREEN_WIDTH / 6, BUTTON_HEIGHT,
                    "Maze (Prim)")
visToggleButton = Button(ColorSettings.GREY, SCREEN_WIDTH / 3, SCREEN_WIDTH + BUTTON_HEIGHT * 2, SCREEN_WIDTH / 3,
                         BUTTON_HEIGHT,
                         f"Visualise: {str(VISUALISE)}")

pygame.display.set_caption("Pathfinder")

# Loop until the user clicks the close Button.
done = False

# Used to manage how fast the screen updates
clock = pygame.time.Clock()

# -------- Main Program Loop -----------
while not done:
    # --- Main event loop
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True

        elif event.type == pygame.MOUSEBUTTONDOWN:
            pos = pygame.mouse.get_pos()

            # Find out which keys have been pressed
            pressed = pygame.key.get_pressed()

            # If click is inside grid
            if pos[1] <= SCREEN_WIDTH - 1:

                # Change the x/y screen coordinates to grid coordinates
                column = pos[0] // (WIDTH + MARGIN)
                row = pos[1] // (HEIGHT + MARGIN)

                if (row, column) == START_POINT:
                    drag_start_point = True
                elif (row, column) == END_POINT:
                    drag_end_point = True
                else:
                    cell_updated = grid[row][column]
                    if pressed[pygame.K_LCTRL]:
                        update_cell_to = 'mud'
                    else:
                        update_cell_to = 'wall'
                    cell_updated.update(nodetype=update_cell_to)
                    mouse_drag = True
                    if algorithm_run and cell_updated.is_path == True:
                        path_found = update_path()



            # When the Dijkstra Button is clicked
            elif dijkstraButton.isOver(pos):
                clear_visited()
                update_gui(draw_background=False, draw_buttons=False)
                if VISUALISE:
                    pygame.display.flip()
                path_found = dijkstra(grid, START_POINT, END_POINT)
                grid[START_POINT[0]][START_POINT[1]].update(nodetype='start')
                algorithm_run = 'dijkstra'

            # When the Reset Button is clicked
            elif resetButton.isOver(pos):
                path_found = False
                algorithm_run = False
                for row in range(ROWS):
                    for column in range(ROWS):
                        if (row, column) != START_POINT and (row, column) != END_POINT:
                            grid[row][column].update(nodetype='blank', is_visited=False, is_path=False)

            # When the Prim Button is clicked
            elif mazeButton.isOver(pos):
                path_found = False
                algorithm_run = False
                for row in range(ROWS):
                    for column in range(ROWS):
                        if (row, column) != START_POINT and (row, column) != END_POINT:
                            grid[row][column].update(nodetype='blank', is_visited=False, is_path=False)
                grid = better_prim()

            # When the Visualisation Toggle Button is clicked
            elif visToggleButton.isOver(pos):
                if VISUALISE:
                    VISUALISE = False
                else:
                    VISUALISE = True


        elif event.type == pygame.MOUSEBUTTONUP:
            # Turn off all mouse drags if mouse Button released
            mouse_drag = drag_end_point = drag_start_point = False

        elif event.type == pygame.MOUSEMOTION:

            # Boolean values saying whether left, middle and right mouse buttons are currently pressed
            left, middle, right = pygame.mouse.get_pressed()

            # Sometimes we get stuck in this loop if the mousebutton is released while not in the pygame screen
            # This acts to break out of that loop
            if not left:
                mouse_drag = drag_end_point = drag_start_point = False
                continue

            # User moves the mouse. Get the position
            pos = pygame.mouse.get_pos()

            # Change the x/y screen coordinates to grid coordinates
            column = pos[0] // (WIDTH + MARGIN)
            row = pos[1] // (HEIGHT + MARGIN)

            # Turn mouse_drag off if mouse goes outside of grid
            if pos[1] >= SCREEN_WIDTH - 2 or pos[1] <= 2 or pos[0] >= SCREEN_WIDTH - 2 or pos[0] <= 2:
                mouse_drag = False
                continue

            cell_updated = grid[row][column]

            # Add walls or sticky mud patches
            if mouse_drag == True:
                if (row, column) == START_POINT:
                    pass
                elif (row, column) == END_POINT:
                    pass
                else:
                    if pressed[pygame.K_LCTRL]:
                        update_cell_to = 'mud'
                    else:
                        update_cell_to = 'wall'
                    cell_updated.update(nodetype=update_cell_to)

                mouse_drag = True

                if algorithm_run:
                    if cell_updated.is_path == True:
                        path_found = update_path()

            # Move the start point
            elif drag_start_point == True:
                if grid[row][column].nodetype == "blank":
                    grid[START_POINT[0]][START_POINT[1]].update(nodetype='blank', is_path=False, is_visited=False)
                    START_POINT = (row, column)
                    grid[START_POINT[0]][START_POINT[1]].update(nodetype='start')
                    # If we have already run the algorithm, update it as the point is moved
                    if algorithm_run:
                        path_found = update_path()
                        grid[START_POINT[0]][START_POINT[1]].update(nodetype='start')

                        # Move the end point
            elif drag_end_point == True:
                if grid[row][column].nodetype == "blank":
                    grid[END_POINT[0]][END_POINT[1]].update(nodetype='blank', is_path=False, is_visited=False)
                    END_POINT = (row, column)
                    grid[END_POINT[0]][END_POINT[1]].update(nodetype='end')
                    # If we have already run the algorithm, update it as the point is moved
                    if algorithm_run:
                        path_found = update_path()
                        grid[START_POINT[0]][START_POINT[1]].update(nodetype='start')

            pygame.display.flip()


    # Game logic

    ### UTILITY FUNCTIONS ###

    # Clear board, keeping excluded nodes
    def clear_visited():
        excluded_nodetypes = ['start', 'end', 'wall', 'mud']
        for row in range(ROWS):
            for column in range(ROWS):
                if grid[row][column].nodetype not in excluded_nodetypes:
                    grid[row][column].update(nodetype="blank", is_visited=False, is_path=False)
                else:
                    grid[row][column].update(is_visited=False, is_path=False)
        update_gui(draw_background=False, draw_buttons=False)


    def update_path(algorithm_run=algorithm_run):

        clear_visited()

        valid_algorithms = ['dijkstra', 'astar', 'dfs', 'bfs']

        assert algorithm_run in valid_algorithms, f"last algorithm used ({algorithm_run}) is not in valid algorithms: {valid_algorithms}"

        if algorithm_run == 'dijkstra':
            path_found = dijkstra(grid, START_POINT, END_POINT, visualise=False)
        else:
            path_found = False
        return path_found


    # Function for moving an item between two dicts
    def dict_move(from_dict, to_dict, item):
        to_dict[item] = from_dict[item]
        from_dict.pop(item)
        return from_dict, to_dict


    # + represents non-diagonal neighbours, x diagonal neighbours
    def get_neighbours(node, max_width=ROWS - 1, diagonals=DIAGONALS):
        if not diagonals:
            neighbours = (
                ((min(max_width, node[0] + 1), node[1]), "+"),
                ((max(0, node[0] - 1), node[1]), "+"),
                ((node[0], min(max_width, node[1] + 1)), "+"),
                ((node[0], max(0, node[1] - 1)), "+")
            )
        else:
            neighbours = (
                ((min(max_width, node[0] + 1), node[1]), "+"),
                ((max(0, node[0] - 1), node[1]), "+"),
                ((node[0], min(max_width, node[1] + 1)), "+"),
                ((node[0], max(0, node[1] - 1)), "+"),
                ((min(max_width, node[0] + 1), min(max_width, node[1] + 1)), "x"),
                ((min(max_width, node[0] + 1), max(0, node[1] - 1)), "x"),
                ((max(0, node[0] - 1), min(max_width, node[1] + 1)), "x"),
                ((max(0, node[0] - 1), max(0, node[1] - 1)), "x")
            )

        # return neighbours
        return (neighbour for neighbour in neighbours if neighbour[0] != node)


    # For Pygame: this draws a square in the given location (for when properties updated)
    def draw_square(row, column, grid=grid):
        pygame.draw.rect(
            screen,
            grid[row][column].color,
            [
                (MARGIN + HEIGHT) * column + MARGIN,
                (MARGIN + HEIGHT) * row + MARGIN,
                WIDTH,
                HEIGHT
            ]
        )
        pygame.event.pump()


    # For Pygame: this updates the screen for the given square
    # (as opposed to pygame.display.flip() which updates the entire screen)
    def update_square(row, column):
        pygame.display.update(
            (MARGIN + WIDTH) * column + MARGIN,
            (MARGIN + HEIGHT) * row + MARGIN,
            WIDTH,
            HEIGHT
        )
        pygame.event.pump()


    ### MAZE CREATION ALGORITHMS ###

    # randomized Prim's algorithm for creating random mazes
    # This version maintains the traditional "maze" look, where a route cannot
    # be diagonally connected to another point on the route
    def better_prim(mazearray=False, start_point=False, visualise=VISUALISE):

        # If a maze isn't input, we just create a grid full of walls
        if not mazearray:
            mazearray = []
            for row in range(ROWS):
                mazearray.append([])
                for column in range(ROWS):
                    if row % 2 != 0 and column % 2 != 0:
                        mazearray[row].append(Node('dormant'))
                    else:
                        mazearray[row].append(Node('wall'))
                    if visualise:
                        draw_square(row, column, grid=mazearray)

        n = len(mazearray) - 1

        if not start_point:
            start_point = (random.randrange(1, n, 2), random.randrange(1, n, 2))
            mazearray[start_point[0]][start_point[1]].update(nodetype='blank')

        if visualise:
            draw_square(start_point[0], start_point[1], grid=mazearray)
            pygame.display.flip()

        walls = set()

        starting_walls = get_neighbours(start_point, n)

        for wall, ntype in starting_walls:
            if mazearray[wall[0]][wall[1]].nodetype == 'wall':
                walls.add(wall)

        # While there are walls in the list (set):
        # Pick a random wall from the list. If only one of the cells that the wall divides is visited, then:
        # # Make the wall a passage and mark the unvisited cell as part of the maze.
        # # Add the neighboring walls of the cell to the wall list.
        # Remove the wall from the list.
        while len(walls) > 0:
            wall = random.choice(tuple(walls))
            visited = 0
            add_to_maze = []

            for wall_neighbour, ntype in get_neighbours(wall, n):
                if mazearray[wall_neighbour[0]][wall_neighbour[1]].nodetype == 'blank':
                    visited += 1

            if visited <= 1:
                mazearray[wall[0]][wall[1]].update(nodetype='blank')

                if visualise:
                    draw_square(wall[0], wall[1], mazearray)
                    update_square(wall[0], wall[1])
                    time.sleep(0.0001)

                # A 'dormant' node (below) is a different type of node I had to create for this algo
                # otherwise the maze generated doesn't look like a traditional maze.
                # Every dormant eventually becomes a blank node, while the regular walls
                # sometimes become a passage between blanks and are sometimes left as walls
                for neighbour, ntype in get_neighbours(wall, n):
                    if mazearray[neighbour[0]][neighbour[1]].nodetype == 'dormant':
                        add_to_maze.append((neighbour[0], neighbour[1]))

                if len(add_to_maze) > 0:
                    cell = add_to_maze.pop()
                    mazearray[cell[0]][cell[1]].update(nodetype='blank')

                    if visualise:
                        draw_square(cell[0], cell[1], mazearray)
                        update_square(cell[0], cell[1])
                        time.sleep(0.0001)

                    for cell_neighbour, ntype in get_neighbours(cell, n):
                        if mazearray[cell_neighbour[0]][cell_neighbour[1]].nodetype == 'wall':
                            walls.add(cell_neighbour)

            walls.remove(wall)

        mazearray[END_POINT[0]][END_POINT[1]].update(nodetype='end')
        mazearray[START_POINT[0]][START_POINT[1]].update(nodetype='start')

        return mazearray


    ### PATHFINDING ALGORITHMS ###

    # Dijkstra's pathfinding algorithm, with the option to switch to A* by adding a heuristic of expected distance to end node
    def dijkstra(mazearray, start_point=(0, 0), goal_node=False, display=pygame.display, visualise=VISUALISE,
                 diagonals=DIAGONALS, astar=False):

        heuristic = 0
        distance = 0

        # Get the dimensions of the (square) maze
        n = len(mazearray) - 1

        # Create the various data structures with speed in mind
        visited_nodes = set()
        unvisited_nodes = set([(x, y) for x in range(n + 1) for y in range(n + 1)])
        queue = AStarQueue()

        queue.push(distance + heuristic, distance, start_point)
        v_distances = {}

        # If a goal_node is not set, put it in the bottom right (1 square away from either edge)
        if not goal_node:
            goal_node = (n, n)
        priority, current_distance, current_node = queue.pop()
        start = time.perf_counter()

        # Main algorithm loop
        while current_node != goal_node and len(unvisited_nodes) > 0:
            if current_node in visited_nodes:
                if len(queue.show()) == 0:
                    return False
                else:
                    priority, current_distance, current_node = queue.pop()
                    continue

            # Call to check neighbours of the current node
            for neighbour in get_neighbours(current_node, n, diagonals=diagonals):
                neighbours_loop(
                    neighbour,
                    mazearr=mazearray,
                    visited_nodes=visited_nodes,
                    unvisited_nodes=unvisited_nodes,
                    queue=queue,
                    v_distances=v_distances,
                    current_node=current_node,
                    current_distance=current_distance,
                    astar=astar
                )

            # When we have checked the current node, add and remove appropriately
            visited_nodes.add(current_node)
            unvisited_nodes.discard(current_node)

            # Add the distance to the visited distances dictionary (used for traceback)
            v_distances[current_node] = current_distance

            # Pygame part: visited nodes mark visited nodes as green
            if (current_node[0], current_node[1]) != start_point:
                mazearray[current_node[0]][current_node[1]].update(is_visited=True)
                draw_square(current_node[0], current_node[1], grid=mazearray)

                # If we want to visualise it (rather than run instantly)
                # then we update the grid with each loop
                if visualise:
                    update_square(current_node[0], current_node[1])
                    time.sleep(0.000001)

            # If there are no nodes in the queue then we return False (no path)
            if len(queue.show()) == 0:
                return False
            # Otherwise we take the minimum distance as the new current node
            else:
                priority, current_distance, current_node = queue.pop()

        v_distances[goal_node] = current_distance + (1 if not diagonals else 2 ** 0.5)
        visited_nodes.add(goal_node)

        # Draw the path back from goal node to start node
        trace_back(goal_node, start_point, v_distances, visited_nodes, n, mazearray, diags=diagonals,
                   visualise=visualise)

        end = time.perf_counter()
        num_visited = len(visited_nodes)
        time_taken = end - start

        # Print timings
        print(
            f"Program finished in {time_taken:.4f} seconds after checking {num_visited} nodes. That is {time_taken / num_visited:.8f} seconds per node.")

        # The commented out line returns the distance to the end node
        # return False if v_distances[goal_node] == float('inf') else v_distances[goal_node]
        return False if v_distances[goal_node] == float('inf') else True


    # (DIJKSTRA/A*) loop to check all neighbours of the "current node"
    def neighbours_loop(neighbour, mazearr, visited_nodes, unvisited_nodes, queue, v_distances, current_node,
                        current_distance, diags=DIAGONALS, astar=False):

        neighbour, ntype = neighbour

        heuristic = 0

        if astar:
            heuristic += abs(END_POINT[0] - neighbour[0]) + abs(END_POINT[1] - neighbour[1])
            heuristic *= 1  # if this goes above 1 then the shortest path is not guaranteed, but the attempted route becomes more direct

        # If the neighbour has already been visited
        if neighbour in visited_nodes:
            pass
        elif mazearr[neighbour[0]][neighbour[1]].nodetype == 'wall':
            visited_nodes.add(neighbour)
            unvisited_nodes.discard(neighbour)
        else:
            modifier = mazearr[neighbour[0]][neighbour[1]].distance_modifier
            if ntype == "+":
                queue.push(current_distance + (1 * modifier) + heuristic, current_distance + (1 * modifier), neighbour)
            elif ntype == "x":
                queue.push(current_distance + ((2 ** 0.5) * modifier) + heuristic,
                           current_distance + ((2 ** 0.5) * modifier), neighbour)


    # (DIJKSTRA/A*) trace a path back from the end node to the start node after the algorithm has been run
    def trace_back(goal_node, start_node, v_distances, visited_nodes, n, mazearray, diags=False, visualise=VISUALISE):

        # begin the list of nodes which will represent the path back, starting with the end node
        path = [goal_node]

        current_node = goal_node

        # Set the loop in motion until we get back to the start
        while current_node != start_node:
            # Start an empty priority queue for the current node to check all neighbours
            neighbour_distances = PriorityQueue()

            neighbours = get_neighbours(current_node, n, diags)

            # Had some errors during testing, not sure if this is still necessary
            try:
                distance = v_distances[current_node]
            except Exception as e:
                print(e)

            # For each neighbour of the current node, add its location and distance
            # to a priority queue
            for neighbour, ntype in neighbours:
                if neighbour in v_distances:
                    distance = v_distances[neighbour]
                    neighbour_distances.push(distance, neighbour)

            # Pop the lowest value off; that is the next node in our path
            distance, smallest_neighbour = neighbour_distances.pop()
            mazearray[smallest_neighbour[0]][smallest_neighbour[1]].update(is_path=True)

            # Update pygame display
            draw_square(smallest_neighbour[0], smallest_neighbour[1], grid=mazearray)
            # update_square(smallest_neighbour[0],smallest_neighbour[1])

            path.append(smallest_neighbour)
            current_node = smallest_neighbour

        pygame.display.flip()

        mazearray[start_node[0]][start_node[1]].update(is_path=True)


    grid[START_POINT[0]][START_POINT[1]].update(nodetype='start')
    grid[END_POINT[0]][END_POINT[1]].update(nodetype='end')


    # Update the GUI
    def update_gui(draw_background=True, draw_buttons=True, draw_grid=True):

        if draw_background:
            # Draw a black background to set everything on
            screen.fill(ColorSettings.BLACK)
            pass

        if draw_buttons:
            visToggleButton = Button(ColorSettings.GREY, SCREEN_WIDTH / 3, SCREEN_WIDTH + BUTTON_HEIGHT * 2,
                                     SCREEN_WIDTH / 3,
                                     BUTTON_HEIGHT, f"Visualise: {str(VISUALISE)}")
            # Draw Button below grid
            dijkstraButton.draw(screen, (0, 0, 0))
            resetButton.draw(screen, (0, 0, 0))
            mazeButton.draw(screen, (0, 0, 0))
            visToggleButton.draw(screen, (0, 0, 0))

        if draw_grid:
            # Draw the grid
            for row in range(ROWS):
                for column in range(ROWS):
                    color = grid[row][column].color
                    draw_square(row, column)


    # --- Drawing code should go here
    update_gui()

    # --- Go ahead and update the screen with what we've drawn.
    pygame.display.flip()

    # --- Limit to 60 frames per second
    clock.tick(60)

# Close the window and quit.
pygame.quit()
