#pragma once
#ifdef _WIN32
namespace rths {

class DeformerDXR
{
public:
    DeformerDXR(ID3D12Device5Ptr device, ID3D12FencePtr fence);
    ~DeformerDXR();

    bool queueDeformCommand(MeshInstanceDataDXR& inst);

private:
    ID3D12Device5Ptr m_device;
    ID3D12FencePtr m_fence;

    ID3D12CommandAllocatorPtr m_cmd_allocator;
    ID3D12GraphicsCommandList4Ptr m_cmd_list;
    ID3D12CommandQueuePtr m_cmd_queue;

    ID3D12RootSignaturePtr m_rootsig_deform;
    ID3D12PipelineStatePtr m_pipeline_state;
};
using DeformerDXRPtr = std::shared_ptr<DeformerDXR>;

} // namespace rths
#endif // _WIN32