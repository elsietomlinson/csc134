import pygame
import sys

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

# Set initial velocity (controls direction and speed)
vx = 2  # horizontal speed
vy = 2  # vertical speed

clock = pygame.time.Clock()

# --- Main Game Loop ---
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Update position
    x += vx
    y += vy

    # Bounce off edges
    if x - radius <= 0 or x + radius >= width:
        vx = -vx
    if y - radius <= 0 or y + radius >= height:
        vy = -vy

    # Fill background and draw ball
    screen.fill((0, 0, 0))
    pygame.draw.circle(screen, (51, 102, 0), (x, y), radius)

    pygame.display.flip()
    clock.tick(60)  # controls frame rate (60 FPS)

# Quit
pygame.quit()
sys.exit()