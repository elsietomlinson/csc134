import pygame
import sys
import math  # <-- add this for sin()

# Initialize Pygame
pygame.init()

# Set up the display
width, height = 600, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Pygame Test Window")

# --- Main Game Setup ---
x = width // 2
y = height // 2
radius = 50

# Velocity (speed and direction)
vx = 2
vy = 2

clock = pygame.time.Clock()

# --- Main Game Loop ---
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Move the ball
    x += vx
    y += vy

    # Bounce off walls
    if x - radius <= 0 or x + radius >= width:
        vx = -vx
    if y - radius <= 0 or y + radius >= height:
        vy = -vy

    # Smooth color cycling between light and dark green
    t = pygame.time.get_ticks() * 0.002  # time in milliseconds
    green_value = 102 + int(50 * (1 + math.sin(t)))  # oscillates between 102–202
    color = (51, green_value, 0)

    # Draw background and circle
    screen.fill((0, 0, 0))
    pygame.draw.circle(screen, color, (x, y), radius)

    pygame.display.flip()
    clock.tick(60)

# Quit Pygame
pygame.quit()
sys.exit()