# Lab Program

This repository adheres to high engineering standards, prioritizing continuous improvement, robust error handling, and clean, modular design. It contains a collection of programs for various labs including Web Development (HTML/JS), Java, and C.

## 🏗️ System Architecture

The ecosystem relies on an NGINX container to serve the static frontend lab code, with backend components configured for independent execution.

```mermaid
graph TD
    subgraph Client
        Browser[Web Browser]
    end

    subgraph Container Ecosystem [Container Ecosystem]
        Nginx[NGINX Web Server]
        FEWD[Frontend Lab Files]
        Nginx -- "Serves" --> FEWD
    end

    subgraph Source Code [Source Code]
        SrcDir[src/]
        TestsDir[tests/]
        SrcDir --> JavaLab[Java Programs]
        SrcDir --> CLab[C Programs]
        SrcDir --> WebLab[HTML/JS Programs]
    end

    Browser -- "HTTP Request (Port 8080)" --> Nginx
    CI[GitHub Actions CI] -- "Build & Test" --> Source Code
```

## 🛠️ Step-by-Step Setup

1. **Prerequisites**: Ensure you have Docker and Docker Compose installed on your local machine.
2. **Clone the repository**:
   ```bash
   git clone <repository_url>
   cd lab-program
   ```
3. **Start the environment**:
   ```bash
   docker-compose up --build -d
   ```
4. **Access the application**: Open your web browser and navigate to `http://localhost:8080`.
5. **Shut down**: When you are finished, you can stop the container ecosystem gracefully:
   ```bash
   docker-compose down
   ```

## 📂 Repository Structure

- `/src/`: Contains all core implementations, logically separated by lab topics.
- `/tests/`: Reserved for isolated unit testing and quality assurance logic.
- `.github/workflows/`: Houses CI/CD pipelines to ensure code reliability across branches.

## 📦 Dependency Rationale

- **NGINX (Alpine)**: Chosen as the base image for the frontend components due to its ultra-low memory footprint, high performance in static file serving, and battle-tested security.
- **Docker & Docker Compose**: Selected to guarantee consistent execution environments, removing "it works on my machine" issues and enabling seamless onboarding.
- **GitHub Actions**: Integrated directly into the repository for automated CI, executing build tests to prevent regressions.

## 🛡️ Error Handling Philosophy

All core execution paths, specifically Java main entry points, are wrapped in comprehensive error-handling guards. This prevents total system failure on unexpected input, logging critical exceptions before exiting gracefully.
