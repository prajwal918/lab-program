# Stage 1: Security and validation (Base layer)
FROM alpine:3.18 AS security-check
RUN apk add --no-cache curl

# Stage 2: Serve using NGINX
FROM nginx:1.25-alpine

LABEL maintainer="engineering-team"
LABEL version="1.0"
LABEL description="Lab Program Web Server with Enterprise Standards"

# Remove default nginx static assets
RUN rm -rf /usr/share/nginx/html/*

# Copy FEWD LAB as the main web application
COPY src/FEWD\ LAB /usr/share/nginx/html/

# Secure the container by running as non-root
RUN chown -R nginx:nginx /usr/share/nginx/html && \
    chmod -R 755 /usr/share/nginx/html && \
    chown -R nginx:nginx /var/cache/nginx && \
    chown -R nginx:nginx /var/log/nginx && \
    chown -R nginx:nginx /etc/nginx/conf.d
RUN touch /var/run/nginx.pid && \
    chown -R nginx:nginx /var/run/nginx.pid

USER nginx

# Healthcheck for robust orchestration
HEALTHCHECK --interval=30s --timeout=5s --start-period=5s --retries=3 \
  CMD curl -f http://localhost:80/ || exit 1

EXPOSE 80

CMD ["nginx", "-g", "daemon off;"]