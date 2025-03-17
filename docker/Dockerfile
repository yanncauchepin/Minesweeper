# Use Ubuntu 24.04 as the base image
FROM ubuntu:24.04

# Install runtime dependencies for wxWidgets.
# Note: Verify that the package names remain the same in Ubuntu 24.04.
RUN apt-get update && apt-get install -y \
    libwxgtk3.2-dev \
    && rm -rf /var/lib/apt/lists/*

# Set the DISPLAY environment variable for X11.
ENV DISPLAY=:0

# Mount the X11 Unix socket (if running GUI apps)
VOLUME /tmp/.X11-unix

# Copy your wxWidgets executable into the image.
COPY wxGame /usr/local/bin/wxminesweeper

# Ensure the executable has the right permissions.
RUN chmod +x /usr/local/bin/wxminesweeper

# Define the default command.
CMD ["/usr/local/bin/wxminesweeper"]
