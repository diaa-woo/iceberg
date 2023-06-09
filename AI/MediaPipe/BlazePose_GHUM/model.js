import * as poseDetection from '@tensorflow-models/pose-detection';
import '@mediapipe/pose';

document.addEventListener("DOMContentLoaded", () => {
    new App();
})

class App {
    constructor() {
        const model = poseDetection.SupportedModels.BlazePose;
        const detectorConfig = {
            runtime: 'mediapipe',
            modelType: 'full'
        };
        detector = await poseDetection.createDetector(model, detectorConfig);

        const video = document.querySelector('#video');
        const poses = await detector.estimatePoses(video);

        if(navigator.mediaDevices.getUserMedia) {
            navigator.mediaDevices.getUserMedia({video: true})
                .then((stream) => {
                    video.srcObject = stream;
                })
                .catch(function(error) {
                    console.log("Something went wrong!");
                    console.log(error);
                    return;
                });
        }

        video.addEventListener("loadedmetadata", () => {
            window.requestAnimationFrame(this.draw.bind(this));
        })
    }

    draw(t) {
        window.requestAnimationFrame(this.draw.bind(this));
    }
}