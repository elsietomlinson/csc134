import pygame
import sys
import math

# Initialize Pygame
pygame.init()

# Set up display
width, height = 600, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Jelly Ball Bounce")

# --- Main Setup ---
x = width // 2
y = height // 2
radius = 50

vx = 3
vy = 3

squash_x = 1.0  # scale factors for jelly effect
squash_y = 1.0
squash_speed = 0.15  # how fast it returns to normal shape

clock = pygame.time.Clock()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Move ball
    x += vx
    y += vy

    # Bounce detection
    bounced = False
    if x - radius <= 0 or x + radius >= width:
        vx = -vx
        bounced = True
        squash_x, squash_y = 1.3, 0.7  # squish horizontally
    if y - radius <= 0 or y + radius >= height:
        vy = -vy
        bounced = True
        squash_x, squash_y = 0.7, 1.3  # squish vertically

    # Smoothly return to normal shape
    squash_x += (1.0 - squash_x) * squash_speed
    squash_y += (1.0 - squash_y) * squash_speed

    # Color shift (light to dark green)
    t = pygame.time.get_ticks() * 0.002
    green_value = 102 + int(50 * (1 + math.sin(t)))
    color = (51, green_value, 0)

    # Draw background and squishy ball
    screen.fill((0, 0, 0))
    ellipse_rect = pygame.Rect(0, 0, int(radius * 2 * squash_x), int(radius * 2 * squash_y))
    ellipse_rect.center = (x, y)
    pygame.draw.ellipse(screen, color, ellipse_rect)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()